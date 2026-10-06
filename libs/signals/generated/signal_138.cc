#include "libs/signals/signal.h"

namespace signals {

double Signal138(const Ticks& ticks) {
  return Evaluate<138, 112>(ticks) + Evaluate<1138, 112>(ticks);
}

}
