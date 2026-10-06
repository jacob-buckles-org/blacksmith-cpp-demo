#pragma once

#include <cmath>
#include <cstdint>
#include <string>

namespace marketdata {

enum class Side { kBuy, kSell };

struct Price {
  static constexpr int64_t kTicksPerUnit = 10000;
  int64_t ticks = 0;

  static Price FromDouble(double v) { return Price{static_cast<int64_t>(std::llround(v * kTicksPerUnit))}; }
  double ToDouble() const { return static_cast<double>(ticks) / kTicksPerUnit; }

  friend bool operator<(Price a, Price b) { return a.ticks < b.ticks; }
  friend bool operator>(Price a, Price b) { return a.ticks > b.ticks; }
  friend bool operator<=(Price a, Price b) { return a.ticks <= b.ticks; }
  friend bool operator>=(Price a, Price b) { return a.ticks >= b.ticks; }
  friend bool operator==(Price a, Price b) { return a.ticks == b.ticks; }
};

struct Order {
  uint64_t id = 0;
  std::string symbol;
  Side side = Side::kBuy;
  Price price;
  int64_t qty = 0;
};

struct Trade {
  uint64_t buy_id = 0;
  uint64_t sell_id = 0;
  std::string symbol;
  Price price;
  int64_t qty = 0;
};

struct Tick {
  std::string symbol;
  Price price;
  int64_t qty = 0;
};

}
