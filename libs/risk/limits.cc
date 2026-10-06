#include "libs/risk/limits.h"

#include <cstdlib>

#include "absl/strings/str_cat.h"

namespace risk {

absl::Status RiskChecker::CheckOrder(const marketdata::Order& order) const {
  auto it = limits_.find(order.symbol);
  if (it == limits_.end()) return absl::FailedPreconditionError(absl::StrCat("no limits for ", order.symbol));
  const Limits& l = it->second;
  if (order.qty > l.max_order_qty) return absl::OutOfRangeError("order qty over limit");
  const int64_t signed_qty = order.side == marketdata::Side::kBuy ? order.qty : -order.qty;
  if (std::llabs(Position(order.symbol) + signed_qty) > l.max_position) {
    return absl::OutOfRangeError("position over limit");
  }
  return absl::OkStatus();
}

void RiskChecker::OnTrade(const marketdata::Trade& trade, uint64_t our_order_id) {
  if (trade.buy_id == our_order_id) positions_[trade.symbol] += trade.qty;
  if (trade.sell_id == our_order_id) positions_[trade.symbol] -= trade.qty;
}

int64_t RiskChecker::Position(const std::string& symbol) const {
  auto it = positions_.find(symbol);
  return it == positions_.end() ? 0 : it->second;
}

}
