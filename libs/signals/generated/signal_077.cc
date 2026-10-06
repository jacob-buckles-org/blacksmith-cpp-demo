#include "libs/signals/signal.h"

namespace signals {

double Signal077(const Ticks& ticks) {
  return Evaluate<77, 112>(ticks) + Evaluate<1077, 112>(ticks);
}

}
