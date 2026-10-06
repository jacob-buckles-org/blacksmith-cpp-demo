#include "libs/signals/signal.h"

namespace signals {

double Signal180(const Ticks& ticks) {
  return Evaluate<180, 112>(ticks) + Evaluate<1180, 112>(ticks);
}

}
