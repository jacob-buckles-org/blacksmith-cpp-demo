#pragma once

#include <cstdint>
#include <deque>
#include <functional>
#include <optional>
#include <string>
#include <vector>

#include "absl/container/btree_map.h"
#include "absl/container/flat_hash_map.h"
#include "libs/marketdata/types.h"

namespace orderbook {

using marketdata::Order;
using marketdata::Price;
using marketdata::Side;
using marketdata::Trade;

class OrderBook {
 public:
  explicit OrderBook(std::string symbol) : symbol_(std::move(symbol)) {}

  std::vector<Trade> Add(Order order);
  bool Cancel(uint64_t id);

  std::optional<Price> BestBid() const;
  std::optional<Price> BestAsk() const;
  int64_t DepthAt(Side side, Price price) const;
  size_t OrderCount() const { return index_.size(); }

 private:
  struct Location {
    Side side;
    Price price;
  };

  template <typename Levels>
  void Match(Order& taker, Levels& levels, std::vector<Trade>& trades);

  std::string symbol_;
  absl::btree_map<Price, std::deque<Order>, std::greater<Price>> bids_;
  absl::btree_map<Price, std::deque<Order>, std::less<Price>> asks_;
  absl::flat_hash_map<uint64_t, Location> index_;
};

}
