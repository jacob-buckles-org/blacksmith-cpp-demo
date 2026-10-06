#include "libs/signals/signal.h"

namespace signals {

double Signal101(const Ticks& ticks) {
  return Evaluate<101, 112>(ticks) + Evaluate<1101, 112>(ticks);
}

}
