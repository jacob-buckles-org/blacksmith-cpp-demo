#!/usr/bin/env python3
import argparse
import pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
OUT = ROOT / "libs" / "signals" / "generated"

SIGNAL = """#include "libs/signals/signal.h"

namespace signals {{

double Signal{n:03d}(const Ticks& ticks) {{
  return Evaluate<{n}, {width}>(ticks) + Evaluate<{n2}, {width}>(ticks);
}}

}}
"""

INDEX = """#include "libs/signals/signal.h"

namespace signals {{

{decls}

const std::vector<SignalInfo>& AllSignals() {{
  static const std::vector<SignalInfo> kAll = {{
{entries}
  }};
  return kAll;
}}

}}
"""


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--count", type=int, default=200)
    p.add_argument("--width", type=int, default=112)
    args = p.parse_args()

    OUT.mkdir(parents=True, exist_ok=True)
    for f in OUT.glob("*.cc"):
        f.unlink()

    for n in range(args.count):
        (OUT / f"signal_{n:03d}.cc").write_text(SIGNAL.format(n=n, n2=n + 1000, width=args.width))

    decls = "\n".join(f"double Signal{n:03d}(const Ticks& ticks);" for n in range(args.count))
    entries = "\n".join(f'      {{"signal_{n:03d}", &Signal{n:03d}}},' for n in range(args.count))
    (OUT / "all_signals.cc").write_text(INDEX.format(decls=decls, entries=entries))


if __name__ == "__main__":
    main()
