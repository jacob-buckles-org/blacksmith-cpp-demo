#include "libs/signals/signal.h"

namespace signals {

double Signal005(const Ticks& ticks) {
  return Evaluate<5, 112>(ticks) + Evaluate<1005, 112>(ticks);
}

}
