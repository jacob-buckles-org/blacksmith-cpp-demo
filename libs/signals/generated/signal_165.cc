#include "libs/signals/signal.h"

namespace signals {

double Signal165(const Ticks& ticks) {
  return Evaluate<165, 112>(ticks) + Evaluate<1165, 112>(ticks);
}

}
