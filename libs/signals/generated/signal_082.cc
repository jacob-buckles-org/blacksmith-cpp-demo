#include "libs/signals/signal.h"

namespace signals {

double Signal082(const Ticks& ticks) {
  return Evaluate<82, 112>(ticks) + Evaluate<1082, 112>(ticks);
}

}
