#include "libs/signals/signal.h"

namespace signals {

double Signal095(const Ticks& ticks) {
  return Evaluate<95, 112>(ticks) + Evaluate<1095, 112>(ticks);
}

}
