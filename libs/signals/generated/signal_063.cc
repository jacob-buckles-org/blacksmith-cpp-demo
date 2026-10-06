#include "libs/signals/signal.h"

namespace signals {

double Signal063(const Ticks& ticks) {
  return Evaluate<63, 112>(ticks) + Evaluate<1063, 112>(ticks);
}

}
