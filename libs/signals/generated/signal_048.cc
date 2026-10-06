#include "libs/signals/signal.h"

namespace signals {

double Signal048(const Ticks& ticks) {
  return Evaluate<48, 112>(ticks) + Evaluate<1048, 112>(ticks);
}

}
