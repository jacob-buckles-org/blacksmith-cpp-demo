#include "libs/signals/signal.h"

namespace signals {

double Signal193(const Ticks& ticks) {
  return Evaluate<193, 112>(ticks) + Evaluate<1193, 112>(ticks);
}

}
