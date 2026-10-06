#include "libs/signals/signal.h"

namespace signals {

double Signal125(const Ticks& ticks) {
  return Evaluate<125, 112>(ticks) + Evaluate<1125, 112>(ticks);
}

}
