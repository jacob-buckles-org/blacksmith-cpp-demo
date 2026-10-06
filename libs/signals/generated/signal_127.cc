#include "libs/signals/signal.h"

namespace signals {

double Signal127(const Ticks& ticks) {
  return Evaluate<127, 112>(ticks) + Evaluate<1127, 112>(ticks);
}

}
