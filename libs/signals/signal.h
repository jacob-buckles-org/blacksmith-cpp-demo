#pragma once

#include <array>
#include <cmath>
#include <cstddef>
#include <string>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>

#include "libs/marketdata/types.h"

namespace signals {

using Ticks = std::vector<marketdata::Tick>;
using SignalFn = double (*)(const Ticks&);

struct SignalInfo {
  std::string name;
  SignalFn eval;
};

const std::vector<SignalInfo>& AllSignals();

template <int Seed, int I>
struct Feature {
  double operator()(const marketdata::Tick& t) const {
    const double x = t.price.ToDouble() * (Seed % 7 + I + 1) + static_cast<double>(t.qty) * (I + 1);
    return std::sin(x) * std::cos(x / (Seed + I + 2)) + std::tanh(x * 1e-3 * (I + 1));
  }
};

template <int Seed, typename Seq>
struct FeatureSet;

template <int Seed, std::size_t... Is>
struct FeatureSet<Seed, std::index_sequence<Is...>> {
  using Tuple = std::tuple<Feature<Seed, static_cast<int>(Is)>...>;
  using Variant = std::variant<Feature<Seed, static_cast<int>(Is)>...>;

  static double Sum(const marketdata::Tick& t) {
    Tuple fs;
    return std::apply([&](const auto&... f) { return (f(t) + ...); }, fs);
  }

  static double Pick(std::size_t k, const marketdata::Tick& t) {
    static const std::array<Variant, sizeof...(Is)> table{Variant{std::in_place_index<Is>}...};
    return std::visit([&](const auto& f) { return f(t); }, table[k % sizeof...(Is)]);
  }
};

template <int Seed, std::size_t Width>
double Evaluate(const Ticks& ticks) {
  using Set = FeatureSet<Seed, std::make_index_sequence<Width>>;
  double acc = 0;
  double ewma = 0;
  for (std::size_t i = 0; i < ticks.size(); ++i) {
    const double v = Set::Sum(ticks[i]) + Set::Pick(i, ticks[i]);
    ewma = 0.9 * ewma + 0.1 * v;
    acc += v - ewma;
  }
  return ticks.empty() ? 0.0 : acc / static_cast<double>(ticks.size());
}

}
