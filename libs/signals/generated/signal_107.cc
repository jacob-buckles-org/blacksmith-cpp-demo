#include "libs/signals/signal.h"

namespace signals {

double Signal107(const Ticks& ticks) {
  return Evaluate<107, 112>(ticks) + Evaluate<1107, 112>(ticks);
}

}
