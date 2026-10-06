#include "libs/signals/signal.h"

namespace signals {

double Signal168(const Ticks& ticks) {
  return Evaluate<168, 112>(ticks) + Evaluate<1168, 112>(ticks);
}

}
