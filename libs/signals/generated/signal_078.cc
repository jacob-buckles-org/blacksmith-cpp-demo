#include "libs/signals/signal.h"

namespace signals {

double Signal078(const Ticks& ticks) {
  return Evaluate<78, 112>(ticks) + Evaluate<1078, 112>(ticks);
}

}
