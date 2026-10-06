#include "libs/signals/signal.h"

namespace signals {

double Signal010(const Ticks& ticks) {
  return Evaluate<10, 112>(ticks) + Evaluate<1010, 112>(ticks);
}

}
