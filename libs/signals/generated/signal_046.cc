#include "libs/signals/signal.h"

namespace signals {

double Signal046(const Ticks& ticks) {
  return Evaluate<46, 112>(ticks) + Evaluate<1046, 112>(ticks);
}

}
