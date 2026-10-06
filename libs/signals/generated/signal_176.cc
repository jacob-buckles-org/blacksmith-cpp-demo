#include "libs/signals/signal.h"

namespace signals {

double Signal176(const Ticks& ticks) {
  return Evaluate<176, 112>(ticks) + Evaluate<1176, 112>(ticks);
}

}
