#include "libs/signals/signal.h"

namespace signals {

double Signal167(const Ticks& ticks) {
  return Evaluate<167, 112>(ticks) + Evaluate<1167, 112>(ticks);
}

}
