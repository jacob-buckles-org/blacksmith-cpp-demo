#include "libs/signals/signal.h"

namespace signals {

double Signal177(const Ticks& ticks) {
  return Evaluate<177, 112>(ticks) + Evaluate<1177, 112>(ticks);
}

}
