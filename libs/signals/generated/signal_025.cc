#include "libs/signals/signal.h"

namespace signals {

double Signal025(const Ticks& ticks) {
  return Evaluate<25, 112>(ticks) + Evaluate<1025, 112>(ticks);
}

}
