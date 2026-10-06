#include "libs/signals/signal.h"

namespace signals {

double Signal087(const Ticks& ticks) {
  return Evaluate<87, 112>(ticks) + Evaluate<1087, 112>(ticks);
}

}
