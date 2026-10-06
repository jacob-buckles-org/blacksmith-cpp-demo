#include "libs/signals/signal.h"

namespace signals {

double Signal199(const Ticks& ticks) {
  return Evaluate<199, 112>(ticks) + Evaluate<1199, 112>(ticks);
}

}
