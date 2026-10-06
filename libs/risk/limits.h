#pragma once

#include <cstdint>
#include <string>

#include "absl/container/flat_hash_map.h"
#include "absl/status/status.h"
#include "libs/marketdata/types.h"

namespace risk {

struct Limits {
  int64_t max_position = 0;
  int64_t max_order_qty = 0;
};

class RiskChecker {
 public:
  void SetLimits(const std::string& symbol, Limits limits) { limits_[symbol] = limits; }
  absl::Status CheckOrder(const marketdata::Order& order) const;
  void OnTrade(const marketdata::Trade& trade, uint64_t our_order_id);
  int64_t Position(const std::string& symbol) const;

 private:
  absl::flat_hash_map<std::string, Limits> limits_;
  absl::flat_hash_map<std::string, int64_t> positions_;
};

}
