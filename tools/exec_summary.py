#!/usr/bin/env python3
import collections
import json
import sys


def spawns(path):
    decoder = json.JSONDecoder()
    text = open(path).read()
    i = 0
    while i < len(text):
        while i < len(text) and text[i].isspace():
            i += 1
        if i >= len(text):
            break
        obj, i = decoder.raw_decode(text, i)
        yield obj


def main():
    rows = list(spawns(sys.argv[1]))
    hits = [r for r in rows if r.get("cacheHit")]
    ran = [r for r in rows if not r.get("cacheHit")]
    print(f"| Actions | {len(rows)} |")
    print("|---|---|")
    print(f"| Remote cache hits | {len(hits)} |")
    print(f"| Executed on this runner | {len(ran)} |")
    print()
    if not ran:
        return
    groups = collections.Counter((r.get("targetLabel", "?"), r.get("mnemonic", "?")) for r in ran)
    print("| Executed target | Action | Count |")
    print("|---|---|---|")
    for (label, mnemonic), count in sorted(groups.items())[:40]:
        print(f"| `{label}` | {mnemonic} | {count} |")
    if len(groups) > 40:
        print(f"| ... | {len(groups) - 40} more | |")


if __name__ == "__main__":
    main()
