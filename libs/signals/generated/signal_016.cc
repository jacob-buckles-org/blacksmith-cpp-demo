#include "libs/signals/signal.h"

namespace signals {

double Signal016(const Ticks& ticks) {
  return Evaluate<16, 112>(ticks) + Evaluate<1016, 112>(ticks);
}

}
