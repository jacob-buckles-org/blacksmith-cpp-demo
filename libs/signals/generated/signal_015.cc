#include "libs/signals/signal.h"

namespace signals {

double Signal015(const Ticks& ticks) {
  return Evaluate<15, 112>(ticks) + Evaluate<1015, 112>(ticks);
}

}
