#include "libs/signals/signal.h"

namespace signals {

double Signal017(const Ticks& ticks) {
  return Evaluate<17, 112>(ticks) + Evaluate<1017, 112>(ticks);
}

}
