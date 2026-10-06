#include "libs/signals/signal.h"

namespace signals {

double Signal030(const Ticks& ticks) {
  return Evaluate<30, 112>(ticks) + Evaluate<1030, 112>(ticks);
}

}
