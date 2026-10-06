#include "libs/signals/signal.h"

namespace signals {

double Signal110(const Ticks& ticks) {
  return Evaluate<110, 112>(ticks) + Evaluate<1110, 112>(ticks);
}

}
