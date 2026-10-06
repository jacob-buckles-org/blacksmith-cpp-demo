#include "libs/signals/signal.h"

namespace signals {

double Signal002(const Ticks& ticks) {
  return Evaluate<2, 112>(ticks) + Evaluate<1002, 112>(ticks);
}

}
