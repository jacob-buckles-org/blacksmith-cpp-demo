#include "libs/risk/limits.h"

#include "gtest/gtest.h"

namespace risk {
namespace {

marketdata::Order Buy(int64_t qty) {
  marketdata::Order o;
  o.id = 7;
  o.symbol = "ESZ6";
  o.side = marketdata::Side::kBuy;
  o.qty = qty;
  return o;
}

TEST(Risk, RejectsUnknownSymbol) {
  RiskChecker r;
  EXPECT_FALSE(r.CheckOrder(Buy(1)).ok());
}

TEST(Risk, RejectsNonPositiveQty) {
  RiskChecker r;
  r.SetLimits("ESZ6", Limits{10, 5});
  EXPECT_FALSE(r.CheckOrder(Buy(0)).ok());
  EXPECT_FALSE(r.CheckOrder(Buy(-3)).ok());
}

TEST(Risk, EnforcesOrderAndPositionLimits) {
  RiskChecker r;
  r.SetLimits("ESZ6", Limits{10, 5});
  EXPECT_TRUE(r.CheckOrder(Buy(5)).ok());
  EXPECT_FALSE(r.CheckOrder(Buy(6)).ok());

  marketdata::Trade t;
  t.symbol = "ESZ6";
  t.buy_id = 7;
  t.qty = 8;
  r.OnTrade(t, 7);
  EXPECT_EQ(r.Position("ESZ6"), 8);
  EXPECT_FALSE(r.CheckOrder(Buy(3)).ok());
}

}
}
