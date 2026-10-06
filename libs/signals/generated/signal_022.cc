#include "libs/signals/signal.h"

namespace signals {

double Signal022(const Ticks& ticks) {
  return Evaluate<22, 112>(ticks) + Evaluate<1022, 112>(ticks);
}

}
