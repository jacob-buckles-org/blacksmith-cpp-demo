#include "libs/signals/signal.h"

namespace signals {

double Signal126(const Ticks& ticks) {
  return Evaluate<126, 112>(ticks) + Evaluate<1126, 112>(ticks);
}

}
