#include "libs/signals/signal.h"

namespace signals {

double Signal163(const Ticks& ticks) {
  return Evaluate<163, 112>(ticks) + Evaluate<1163, 112>(ticks);
}

}
