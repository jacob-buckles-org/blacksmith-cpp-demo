#include "libs/signals/signal.h"

namespace signals {

double Signal003(const Ticks& ticks) {
  return Evaluate<3, 112>(ticks) + Evaluate<1003, 112>(ticks);
}

}
