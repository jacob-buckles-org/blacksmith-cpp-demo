#include "libs/signals/signal.h"

namespace signals {

double Signal008(const Ticks& ticks) {
  return Evaluate<8, 112>(ticks) + Evaluate<1008, 112>(ticks);
}

}
