#include "libs/signals/signal.h"

namespace signals {

double Signal106(const Ticks& ticks) {
  return Evaluate<106, 112>(ticks) + Evaluate<1106, 112>(ticks);
}

}
