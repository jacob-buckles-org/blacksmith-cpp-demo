#include "libs/signals/signal.h"

namespace signals {

double Signal142(const Ticks& ticks) {
  return Evaluate<142, 112>(ticks) + Evaluate<1142, 112>(ticks);
}

}
