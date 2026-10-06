#include "libs/signals/signal.h"

namespace signals {

double Signal004(const Ticks& ticks) {
  return Evaluate<4, 112>(ticks) + Evaluate<1004, 112>(ticks);
}

}
