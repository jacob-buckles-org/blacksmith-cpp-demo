#include "libs/signals/signal.h"

namespace signals {

double Signal052(const Ticks& ticks) {
  return Evaluate<52, 112>(ticks) + Evaluate<1052, 112>(ticks);
}

}
