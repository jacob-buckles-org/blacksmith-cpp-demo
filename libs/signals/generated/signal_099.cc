#include "libs/signals/signal.h"

namespace signals {

double Signal099(const Ticks& ticks) {
  return Evaluate<99, 112>(ticks) + Evaluate<1099, 112>(ticks);
}

}
