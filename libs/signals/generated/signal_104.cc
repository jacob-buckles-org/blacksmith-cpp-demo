#include "libs/signals/signal.h"

namespace signals {

double Signal104(const Ticks& ticks) {
  return Evaluate<104, 112>(ticks) + Evaluate<1104, 112>(ticks);
}

}
