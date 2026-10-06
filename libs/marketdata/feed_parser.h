#pragma once

#include <variant>

#include "absl/status/statusor.h"
#include "absl/strings/string_view.h"
#include "libs/marketdata/types.h"

namespace marketdata {

struct AddMsg {
  Order order;
};

struct CancelMsg {
  uint64_t id = 0;
};

using FeedMsg = std::variant<AddMsg, CancelMsg>;

absl::StatusOr<FeedMsg> ParseLine(absl::string_view line);

}
