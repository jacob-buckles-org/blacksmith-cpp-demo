#include "libs/signals/signal.h"

namespace signals {

double Signal083(const Ticks& ticks) {
  return Evaluate<83, 112>(ticks) + Evaluate<1083, 112>(ticks);
}

}
