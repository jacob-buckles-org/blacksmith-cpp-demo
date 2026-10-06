#include "libs/signals/signal.h"

namespace signals {

double Signal049(const Ticks& ticks) {
  return Evaluate<49, 112>(ticks) + Evaluate<1049, 112>(ticks);
}

}
