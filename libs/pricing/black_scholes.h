#pragma once

namespace pricing {

enum class OptionType { kCall, kPut };

struct OptionSpec {
  OptionType type = OptionType::kCall;
  double spot = 0;
  double strike = 0;
  double rate = 0;
  double vol = 0;
  double years = 0;
};

struct Greeks {
  double price = 0;
  double delta = 0;
  double gamma = 0;
  double vega = 0;
  double theta = 0;
};

Greeks Price(const OptionSpec& spec);
double ImpliedVol(const OptionSpec& spec, double market_price);

}
