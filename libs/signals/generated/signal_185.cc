#include "libs/signals/signal.h"

namespace signals {

double Signal185(const Ticks& ticks) {
  return Evaluate<185, 112>(ticks) + Evaluate<1185, 112>(ticks);
}

}
