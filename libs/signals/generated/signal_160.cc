#include "libs/signals/signal.h"

namespace signals {

double Signal160(const Ticks& ticks) {
  return Evaluate<160, 112>(ticks) + Evaluate<1160, 112>(ticks);
}

}
