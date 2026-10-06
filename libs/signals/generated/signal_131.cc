#include "libs/signals/signal.h"

namespace signals {

double Signal131(const Ticks& ticks) {
  return Evaluate<131, 112>(ticks) + Evaluate<1131, 112>(ticks);
}

}
