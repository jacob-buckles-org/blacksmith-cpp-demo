#include "libs/signals/signal.h"

namespace signals {

double Signal143(const Ticks& ticks) {
  return Evaluate<143, 112>(ticks) + Evaluate<1143, 112>(ticks);
}

}
