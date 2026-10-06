#include "libs/signals/signal.h"

#include <cmath>

#include "absl/container/flat_hash_set.h"
#include "gtest/gtest.h"

namespace signals {
namespace {

Ticks SampleTicks() {
  Ticks ticks;
  for (int i = 0; i < 64; ++i) {
    marketdata::Tick t;
    t.symbol = "ESZ6";
    t.price = marketdata::Price::FromDouble(5000 + 0.25 * (i % 9));
    t.qty = 1 + i % 5;
    ticks.push_back(t);
  }
  return ticks;
}

TEST(Signals, AllRegisteredWithUniqueNames) {
  absl::flat_hash_set<std::string> names;
  for (const auto& s : AllSignals()) EXPECT_TRUE(names.insert(s.name).second) << s.name;
  EXPECT_FALSE(AllSignals().empty());
}

TEST(Signals, FiniteAndDeterministic) {
  const Ticks ticks = SampleTicks();
  for (const auto& s : AllSignals()) {
    const double a = s.eval(ticks);
    EXPECT_TRUE(std::isfinite(a)) << s.name;
    EXPECT_EQ(a, s.eval(ticks)) << s.name;
  }
}

}
}
