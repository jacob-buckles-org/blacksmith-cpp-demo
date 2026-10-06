#include "libs/signals/signal.h"

namespace signals {

double Signal001(const Ticks& ticks) {
  return Evaluate<1, 112>(ticks) + Evaluate<1001, 112>(ticks);
}

}
