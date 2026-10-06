#include "libs/signals/signal.h"

namespace signals {

double Signal054(const Ticks& ticks) {
  return Evaluate<54, 112>(ticks) + Evaluate<1054, 112>(ticks);
}

}
