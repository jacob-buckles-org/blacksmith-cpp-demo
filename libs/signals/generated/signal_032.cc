#include "libs/signals/signal.h"

namespace signals {

double Signal032(const Ticks& ticks) {
  return Evaluate<32, 112>(ticks) + Evaluate<1032, 112>(ticks);
}

}
