#include "libs/signals/signal.h"

namespace signals {

double Signal169(const Ticks& ticks) {
  return Evaluate<169, 112>(ticks) + Evaluate<1169, 112>(ticks);
}

}
