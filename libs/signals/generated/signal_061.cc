#include "libs/signals/signal.h"

namespace signals {

double Signal061(const Ticks& ticks) {
  return Evaluate<61, 112>(ticks) + Evaluate<1061, 112>(ticks);
}

}
