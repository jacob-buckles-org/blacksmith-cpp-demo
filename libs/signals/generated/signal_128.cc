#include "libs/signals/signal.h"

namespace signals {

double Signal128(const Ticks& ticks) {
  return Evaluate<128, 112>(ticks) + Evaluate<1128, 112>(ticks);
}

}
