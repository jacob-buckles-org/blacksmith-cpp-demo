#include "libs/signals/signal.h"

namespace signals {

double Signal188(const Ticks& ticks) {
  return Evaluate<188, 112>(ticks) + Evaluate<1188, 112>(ticks);
}

}
