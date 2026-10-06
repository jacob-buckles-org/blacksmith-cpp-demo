#include "libs/signals/signal.h"

namespace signals {

double Signal141(const Ticks& ticks) {
  return Evaluate<141, 112>(ticks) + Evaluate<1141, 112>(ticks);
}

}
