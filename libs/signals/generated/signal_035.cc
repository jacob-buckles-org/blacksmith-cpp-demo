#include "libs/signals/signal.h"

namespace signals {

double Signal035(const Ticks& ticks) {
  return Evaluate<35, 112>(ticks) + Evaluate<1035, 112>(ticks);
}

}
