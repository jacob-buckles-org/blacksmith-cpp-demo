#include "libs/signals/signal.h"

namespace signals {

double Signal066(const Ticks& ticks) {
  return Evaluate<66, 112>(ticks) + Evaluate<1066, 112>(ticks);
}

}
