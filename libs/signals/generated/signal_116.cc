#include "libs/signals/signal.h"

namespace signals {

double Signal116(const Ticks& ticks) {
  return Evaluate<116, 112>(ticks) + Evaluate<1116, 112>(ticks);
}

}
