#include "libs/signals/signal.h"

namespace signals {

double Signal151(const Ticks& ticks) {
  return Evaluate<151, 112>(ticks) + Evaluate<1151, 112>(ticks);
}

}
