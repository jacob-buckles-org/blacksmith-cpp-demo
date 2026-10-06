#include "libs/marketdata/feed_parser.h"

#include <string>
#include <vector>

#include "absl/status/status.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_split.h"

namespace marketdata {

absl::StatusOr<FeedMsg> ParseLine(absl::string_view line) {
  std::vector<absl::string_view> f = absl::StrSplit(line, ',');
  if (f.empty()) return absl::InvalidArgumentError("empty line");

  if (f[0] == "A" && f.size() == 6) {
    AddMsg msg;
    double px = 0;
    if (!absl::SimpleAtoi(f[1], &msg.order.id) || !absl::SimpleAtod(f[4], &px) ||
        !absl::SimpleAtoi(f[5], &msg.order.qty)) {
      return absl::InvalidArgumentError(absl::StrCat("bad add: ", line));
    }
    msg.order.symbol = std::string(f[2]);
    if (f[3] == "B") {
      msg.order.side = Side::kBuy;
    } else if (f[3] == "S") {
      msg.order.side = Side::kSell;
    } else {
      return absl::InvalidArgumentError(absl::StrCat("bad side: ", line));
    }
    msg.order.price = Price::FromDouble(px);
    return msg;
  }

  if (f[0] == "X" && f.size() == 2) {
    CancelMsg msg;
    if (!absl::SimpleAtoi(f[1], &msg.id)) return absl::InvalidArgumentError(absl::StrCat("bad cancel: ", line));
    return msg;
  }

  return absl::InvalidArgumentError(absl::StrCat("unknown message: ", line));
}

}
