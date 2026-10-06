#include "libs/signals/signal.h"

namespace signals {

double Signal166(const Ticks& ticks) {
  return Evaluate<166, 112>(ticks) + Evaluate<1166, 112>(ticks);
}

}
