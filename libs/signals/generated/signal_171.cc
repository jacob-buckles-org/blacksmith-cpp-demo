#include "libs/signals/signal.h"

namespace signals {

double Signal171(const Ticks& ticks) {
  return Evaluate<171, 112>(ticks) + Evaluate<1171, 112>(ticks);
}

}
