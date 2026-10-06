#include "libs/signals/signal.h"

namespace signals {

double Signal139(const Ticks& ticks) {
  return Evaluate<139, 112>(ticks) + Evaluate<1139, 112>(ticks);
}

}
