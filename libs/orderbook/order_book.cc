#include "libs/orderbook/order_book.h"

#include <algorithm>

namespace orderbook {

namespace {

bool Crosses(const Order& taker, Price resting) {
  return taker.side == Side::kBuy ? taker.price >= resting : taker.price <= resting;
}

}

template <typename Levels>
void OrderBook::Match(Order& taker, Levels& levels, std::vector<Trade>& trades) {
  while (taker.qty > 0 && !levels.empty()) {
    auto level = levels.begin();
    if (!Crosses(taker, level->first)) break;

    auto& queue = level->second;
    while (taker.qty > 0 && !queue.empty()) {
      Order& maker = queue.front();
      const int64_t fill = std::min(taker.qty, maker.qty);
      Trade t;
      t.symbol = symbol_;
      t.price = maker.price;
      t.qty = fill;
      t.buy_id = taker.side == Side::kBuy ? taker.id : maker.id;
      t.sell_id = taker.side == Side::kBuy ? maker.id : taker.id;
      trades.push_back(std::move(t));

      taker.qty -= fill;
      maker.qty -= fill;
      if (maker.qty == 0) {
        index_.erase(maker.id);
        queue.pop_front();
      }
    }
    if (queue.empty()) levels.erase(level);
  }
}

std::vector<Trade> OrderBook::Add(Order order) {
  std::vector<Trade> trades;
  if (order.side == Side::kBuy) {
    Match(order, asks_, trades);
    if (order.qty > 0) {
      index_[order.id] = {order.side, order.price};
      bids_[order.price].push_back(std::move(order));
    }
  } else {
    Match(order, bids_, trades);
    if (order.qty > 0) {
      index_[order.id] = {order.side, order.price};
      asks_[order.price].push_back(std::move(order));
    }
  }
  return trades;
}

bool OrderBook::Cancel(uint64_t id) {
  auto it = index_.find(id);
  if (it == index_.end()) return false;
  const Location loc = it->second;
  index_.erase(it);

  auto remove = [&](auto& levels) {
    auto level = levels.find(loc.price);
    if (level == levels.end()) return;
    auto& queue = level->second;
    queue.erase(std::remove_if(queue.begin(), queue.end(), [&](const Order& o) { return o.id == id; }), queue.end());
    if (queue.empty()) levels.erase(level);
  };
  if (loc.side == Side::kBuy) {
    remove(bids_);
  } else {
    remove(asks_);
  }
  return true;
}

std::optional<Price> OrderBook::BestBid() const {
  if (bids_.empty()) return std::nullopt;
  return bids_.begin()->first;
}

std::optional<Price> OrderBook::BestAsk() const {
  if (asks_.empty()) return std::nullopt;
  return asks_.begin()->first;
}

int64_t OrderBook::DepthAt(Side side, Price price) const {
  auto sum = [&](const auto& levels) -> int64_t {
    auto level = levels.find(price);
    if (level == levels.end()) return 0;
    int64_t total = 0;
    for (const auto& o : level->second) total += o.qty;
    return total;
  };
  return side == Side::kBuy ? sum(bids_) : sum(asks_);
}

}
