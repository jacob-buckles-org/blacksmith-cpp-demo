#include "libs/signals/signal.h"

namespace signals {

double Signal134(const Ticks& ticks) {
  return Evaluate<134, 112>(ticks) + Evaluate<1134, 112>(ticks);
}

}
