#include "libs/pricing/black_scholes.h"

#include <cmath>

#include "gtest/gtest.h"

namespace pricing {
namespace {

OptionSpec Spec(OptionType type) {
  OptionSpec s;
  s.type = type;
  s.spot = 100;
  s.strike = 105;
  s.rate = 0.04;
  s.vol = 0.25;
  s.years = 0.5;
  return s;
}

TEST(BlackScholes, PutCallParity) {
  const double call = Price(Spec(OptionType::kCall)).price;
  const double put = Price(Spec(OptionType::kPut)).price;
  EXPECT_NEAR(call - put, 100 - 105 * std::exp(-0.04 * 0.5), 1e-9);
}

TEST(BlackScholes, ImpliedVolRoundTrips) {
  const OptionSpec s = Spec(OptionType::kCall);
  EXPECT_NEAR(ImpliedVol(s, Price(s).price), 0.25, 1e-8);
}

TEST(BlackScholes, DeltaBounds) {
  EXPECT_GT(Price(Spec(OptionType::kCall)).delta, 0);
  EXPECT_LT(Price(Spec(OptionType::kPut)).delta, 0);
}

}
}
