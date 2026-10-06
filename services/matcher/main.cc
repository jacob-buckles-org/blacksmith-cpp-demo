#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/strings/str_format.h"
#include "libs/marketdata/feed_parser.h"
#include "libs/orderbook/order_book.h"
#include "libs/pricing/black_scholes.h"
#include "libs/signals/signal.h"

namespace {

std::vector<std::string> SyntheticFeed(int n) {
  std::mt19937_64 rng(42);
  std::normal_distribution<double> px(0, 0.75);
  std::uniform_int_distribution<int> qty(1, 20);
  const std::vector<std::string> symbols = {"ESZ6", "NQZ6", "RTYZ6"};
  std::vector<std::string> lines;
  for (int i = 1; i <= n; ++i) {
    if (i > 10 && i % 7 == 0) {
      lines.push_back(absl::StrFormat("X,%d", i - 5));
      continue;
    }
    const bool buy = rng() % 2 == 0;
    const double price = 5000 + 0.25 * static_cast<int>(px(rng) * 4);
    lines.push_back(absl::StrFormat("A,%d,%s,%s,%.2f,%d", i, symbols[i % symbols.size()], buy ? "B" : "S", price, qty(rng)));
  }
  return lines;
}

}

int main(int argc, char** argv) {
  std::vector<std::string> lines;
  if (argc > 1) {
    std::ifstream in(argv[1]);
    for (std::string line; std::getline(in, line);) lines.push_back(line);
  } else {
    lines = SyntheticFeed(50000);
  }

  absl::flat_hash_map<std::string, std::unique_ptr<orderbook::OrderBook>> books;
  absl::flat_hash_map<uint64_t, std::string> symbol_of;
  absl::flat_hash_map<std::string, signals::Ticks> prints;
  int64_t rejects = 0;

  for (const auto& line : lines) {
    auto msg = marketdata::ParseLine(line);
    if (!msg.ok()) {
      ++rejects;
      continue;
    }
    if (auto* add = std::get_if<marketdata::AddMsg>(&*msg)) {
      auto& book = books[add->order.symbol];
      if (!book) book = std::make_unique<orderbook::OrderBook>(add->order.symbol);
      symbol_of[add->order.id] = add->order.symbol;
      for (const auto& t : book->Add(add->order)) prints[t.symbol].push_back({t.symbol, t.price, t.qty});
    } else if (auto* cancel = std::get_if<marketdata::CancelMsg>(&*msg)) {
      auto it = symbol_of.find(cancel->id);
      if (it != symbol_of.end()) books[it->second]->Cancel(cancel->id);
    }
  }

  for (const auto& [symbol, book] : books) {
    const auto& all = prints[symbol];
    const signals::Ticks ticks(all.size() > 256 ? all.end() - 256 : all.begin(), all.end());
    double signal = 0;
    for (const auto& s : signals::AllSignals()) signal += s.eval(ticks);

    pricing::OptionSpec spec;
    spec.spot = ticks.empty() ? 5000 : ticks.back().price.ToDouble();
    spec.strike = 5000;
    spec.rate = 0.04;
    spec.vol = 0.18;
    spec.years = 30.0 / 365;

    std::cout << absl::StrFormat("%-6s resting=%-6d prints=%-6d bid=%.2f ask=%.2f signal=%+.4f atm_call=%.2f\n", symbol,
                                 book->OrderCount(), all.size(), book->BestBid() ? book->BestBid()->ToDouble() : 0.0,
                                 book->BestAsk() ? book->BestAsk()->ToDouble() : 0.0, signal, pricing::Price(spec).price);
  }
  std::cout << absl::StrFormat("messages=%d rejects=%d\n", lines.size(), rejects);
  return 0;
}
