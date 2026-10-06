#include "libs/signals/signal.h"

namespace signals {

double Signal047(const Ticks& ticks) {
  return Evaluate<47, 112>(ticks) + Evaluate<1047, 112>(ticks);
}

}
