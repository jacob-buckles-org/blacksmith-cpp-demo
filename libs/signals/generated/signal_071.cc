#include "libs/signals/signal.h"

namespace signals {

double Signal071(const Ticks& ticks) {
  return Evaluate<71, 112>(ticks) + Evaluate<1071, 112>(ticks);
}

}
