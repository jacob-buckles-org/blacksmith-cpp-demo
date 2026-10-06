#include "libs/signals/signal.h"

namespace signals {

double Signal096(const Ticks& ticks) {
  return Evaluate<96, 112>(ticks) + Evaluate<1096, 112>(ticks);
}

}
