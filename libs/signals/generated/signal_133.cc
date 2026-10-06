#include "libs/signals/signal.h"

namespace signals {

double Signal133(const Ticks& ticks) {
  return Evaluate<133, 112>(ticks) + Evaluate<1133, 112>(ticks);
}

}
