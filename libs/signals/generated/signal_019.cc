#include "libs/signals/signal.h"

namespace signals {

double Signal019(const Ticks& ticks) {
  return Evaluate<19, 112>(ticks) + Evaluate<1019, 112>(ticks);
}

}
