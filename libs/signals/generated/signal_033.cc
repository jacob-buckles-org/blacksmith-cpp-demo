#include "libs/signals/signal.h"

namespace signals {

double Signal033(const Ticks& ticks) {
  return Evaluate<33, 112>(ticks) + Evaluate<1033, 112>(ticks);
}

}
