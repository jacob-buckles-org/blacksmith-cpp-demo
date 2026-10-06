#include "libs/signals/signal.h"

namespace signals {

double Signal135(const Ticks& ticks) {
  return Evaluate<135, 112>(ticks) + Evaluate<1135, 112>(ticks);
}

}
