#include "libs/signals/signal.h"

namespace signals {

double Signal140(const Ticks& ticks) {
  return Evaluate<140, 112>(ticks) + Evaluate<1140, 112>(ticks);
}

}
