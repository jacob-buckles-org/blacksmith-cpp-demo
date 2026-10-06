#include "libs/signals/signal.h"

namespace signals {

double Signal034(const Ticks& ticks) {
  return Evaluate<34, 112>(ticks) + Evaluate<1034, 112>(ticks);
}

}
