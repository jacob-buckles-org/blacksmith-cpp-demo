#include "libs/signals/signal.h"

namespace signals {

double Signal051(const Ticks& ticks) {
  return Evaluate<51, 112>(ticks) + Evaluate<1051, 112>(ticks);
}

}
