#include "libs/signals/signal.h"

namespace signals {

double Signal093(const Ticks& ticks) {
  return Evaluate<93, 112>(ticks) + Evaluate<1093, 112>(ticks);
}

}
