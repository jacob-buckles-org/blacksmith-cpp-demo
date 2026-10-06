#include "libs/signals/signal.h"

namespace signals {

double Signal075(const Ticks& ticks) {
  return Evaluate<75, 112>(ticks) + Evaluate<1075, 112>(ticks);
}

}
