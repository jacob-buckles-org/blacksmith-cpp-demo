# blacksmith-cpp-demo

A small C++ trading-style monorepo used to demo GitHub Actions on Blacksmith.

| Path | What |
|---|---|
| `libs/marketdata` | Feed message types and parser |
| `libs/orderbook` | Price-time priority limit order book |
| `libs/pricing` | Black-Scholes pricing, greeks, implied vol |
| `libs/risk` | Order and position limit checks |
| `libs/signals` | Generated, template-heavy signal library |
| `services/matcher` | Replays a feed through the books |

Bazel and CMake build the same sources.

```sh
bazel test //...
bazel run //services/matcher

cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build
```

Regenerate the signal library with `tools/gen_signals.py --count N --width W`. More files or a wider width means a heavier cold build.

The Bazel workflow takes a `cold` input on manual runs. It passes `--noremote_accept_cached`, so nothing is read from the remote cache, while results are still uploaded. Each run's summary lists the environment, timings, remote cache hits, and the actions that executed.
