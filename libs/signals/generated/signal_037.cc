#include "libs/signals/signal.h"

namespace signals {

double Signal037(const Ticks& ticks) {
  return Evaluate<37, 112>(ticks) + Evaluate<1037, 112>(ticks);
}

}
