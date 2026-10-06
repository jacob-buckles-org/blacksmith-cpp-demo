#include "libs/signals/signal.h"

namespace signals {

double Signal178(const Ticks& ticks) {
  return Evaluate<178, 112>(ticks) + Evaluate<1178, 112>(ticks);
}

}
