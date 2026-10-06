#include "libs/signals/signal.h"

namespace signals {

double Signal068(const Ticks& ticks) {
  return Evaluate<68, 112>(ticks) + Evaluate<1068, 112>(ticks);
}

}
