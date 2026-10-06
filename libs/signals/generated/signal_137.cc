#include "libs/signals/signal.h"

namespace signals {

double Signal137(const Ticks& ticks) {
  return Evaluate<137, 112>(ticks) + Evaluate<1137, 112>(ticks);
}

}
