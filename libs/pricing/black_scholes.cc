#include "libs/pricing/black_scholes.h"

#include <cmath>

namespace pricing {

namespace {

constexpr double kInvSqrt2Pi = 0.3989422804014327;

double Cdf(double x) { return 0.5 * std::erfc(-x / std::sqrt(2.0)); }
double Pdf(double x) { return kInvSqrt2Pi * std::exp(-0.5 * x * x); }

}

Greeks Price(const OptionSpec& s) {
  const double sqrt_t = std::sqrt(s.years);
  const double d1 = (std::log(s.spot / s.strike) + (s.rate + 0.5 * s.vol * s.vol) * s.years) / (s.vol * sqrt_t);
  const double d2 = d1 - s.vol * sqrt_t;
  const double df = std::exp(-s.rate * s.years);

  Greeks g;
  g.gamma = Pdf(d1) / (s.spot * s.vol * sqrt_t);
  g.vega = s.spot * Pdf(d1) * sqrt_t;
  if (s.type == OptionType::kCall) {
    g.price = s.spot * Cdf(d1) - s.strike * df * Cdf(d2);
    g.delta = Cdf(d1);
    g.theta = -s.spot * Pdf(d1) * s.vol / (2 * sqrt_t) - s.rate * s.strike * df * Cdf(d2);
  } else {
    g.price = s.strike * df * Cdf(-d2) - s.spot * Cdf(-d1);
    g.delta = Cdf(d1) - 1;
    g.theta = -s.spot * Pdf(d1) * s.vol / (2 * sqrt_t) + s.rate * s.strike * df * Cdf(-d2);
  }
  return g;
}

double ImpliedVol(const OptionSpec& spec, double market_price) {
  OptionSpec s = spec;
  s.vol = 0.2;
  for (int i = 0; i < 50; ++i) {
    const Greeks g = Price(s);
    const double diff = g.price - market_price;
    if (std::abs(diff) < 1e-10 || g.vega < 1e-12) break;
    s.vol -= diff / g.vega;
  }
  return s.vol;
}

}
