#include "libs/signals/signal.h"

namespace signals {

double Signal147(const Ticks& ticks) {
  return Evaluate<147, 112>(ticks) + Evaluate<1147, 112>(ticks);
}

}
