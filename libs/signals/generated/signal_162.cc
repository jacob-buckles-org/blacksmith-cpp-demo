#include "libs/signals/signal.h"

namespace signals {

double Signal162(const Ticks& ticks) {
  return Evaluate<162, 112>(ticks) + Evaluate<1162, 112>(ticks);
}

}
