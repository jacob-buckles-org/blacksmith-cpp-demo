#include "libs/signals/signal.h"

namespace signals {

double Signal006(const Ticks& ticks) {
  return Evaluate<6, 112>(ticks) + Evaluate<1006, 112>(ticks);
}

}
