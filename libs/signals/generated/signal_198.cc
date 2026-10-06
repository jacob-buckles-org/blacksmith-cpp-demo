#include "libs/signals/signal.h"

namespace signals {

double Signal198(const Ticks& ticks) {
  return Evaluate<198, 112>(ticks) + Evaluate<1198, 112>(ticks);
}

}
