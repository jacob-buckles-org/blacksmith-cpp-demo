#include "libs/signals/signal.h"

namespace signals {

double Signal031(const Ticks& ticks) {
  return Evaluate<31, 112>(ticks) + Evaluate<1031, 112>(ticks);
}

}
