#include "libs/signals/signal.h"

namespace signals {

double Signal158(const Ticks& ticks) {
  return Evaluate<158, 112>(ticks) + Evaluate<1158, 112>(ticks);
}

}
