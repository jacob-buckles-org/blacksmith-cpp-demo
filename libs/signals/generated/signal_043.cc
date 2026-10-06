#include "libs/signals/signal.h"

namespace signals {

double Signal043(const Ticks& ticks) {
  return Evaluate<43, 112>(ticks) + Evaluate<1043, 112>(ticks);
}

}
