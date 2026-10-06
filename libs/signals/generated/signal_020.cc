#include "libs/signals/signal.h"

namespace signals {

double Signal020(const Ticks& ticks) {
  return Evaluate<20, 112>(ticks) + Evaluate<1020, 112>(ticks);
}

}
