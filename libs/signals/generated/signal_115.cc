#include "libs/signals/signal.h"

namespace signals {

double Signal115(const Ticks& ticks) {
  return Evaluate<115, 112>(ticks) + Evaluate<1115, 112>(ticks);
}

}
