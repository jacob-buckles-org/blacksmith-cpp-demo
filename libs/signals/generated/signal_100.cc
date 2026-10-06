#include "libs/signals/signal.h"

namespace signals {

double Signal100(const Ticks& ticks) {
  return Evaluate<100, 112>(ticks) + Evaluate<1100, 112>(ticks);
}

}
