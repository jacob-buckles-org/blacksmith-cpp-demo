#include "libs/signals/signal.h"

namespace signals {

double Signal081(const Ticks& ticks) {
  return Evaluate<81, 112>(ticks) + Evaluate<1081, 112>(ticks);
}

}
