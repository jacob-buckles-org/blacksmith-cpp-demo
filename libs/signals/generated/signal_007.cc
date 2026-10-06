#include "libs/signals/signal.h"

namespace signals {

double Signal007(const Ticks& ticks) {
  return Evaluate<7, 112>(ticks) + Evaluate<1007, 112>(ticks);
}

}
