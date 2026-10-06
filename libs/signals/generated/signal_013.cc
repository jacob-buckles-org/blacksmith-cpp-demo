#include "libs/signals/signal.h"

namespace signals {

double Signal013(const Ticks& ticks) {
  return Evaluate<13, 112>(ticks) + Evaluate<1013, 112>(ticks);
}

}
