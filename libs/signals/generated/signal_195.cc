#include "libs/signals/signal.h"

namespace signals {

double Signal195(const Ticks& ticks) {
  return Evaluate<195, 112>(ticks) + Evaluate<1195, 112>(ticks);
}

}
