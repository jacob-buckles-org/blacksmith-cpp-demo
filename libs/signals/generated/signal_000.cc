#include "libs/signals/signal.h"

namespace signals {

double Signal000(const Ticks& ticks) {
  return Evaluate<0, 112>(ticks) + Evaluate<1000, 112>(ticks);
}

}
