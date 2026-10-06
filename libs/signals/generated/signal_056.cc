#include "libs/signals/signal.h"

namespace signals {

double Signal056(const Ticks& ticks) {
  return Evaluate<56, 112>(ticks) + Evaluate<1056, 112>(ticks);
}

}
