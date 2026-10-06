#include "libs/signals/signal.h"

namespace signals {

double Signal040(const Ticks& ticks) {
  return Evaluate<40, 112>(ticks) + Evaluate<1040, 112>(ticks);
}

}
