#include "libs/signals/signal.h"

namespace signals {

double Signal065(const Ticks& ticks) {
  return Evaluate<65, 112>(ticks) + Evaluate<1065, 112>(ticks);
}

}
