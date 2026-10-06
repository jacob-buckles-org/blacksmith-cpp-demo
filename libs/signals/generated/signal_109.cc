#include "libs/signals/signal.h"

namespace signals {

double Signal109(const Ticks& ticks) {
  return Evaluate<109, 112>(ticks) + Evaluate<1109, 112>(ticks);
}

}
