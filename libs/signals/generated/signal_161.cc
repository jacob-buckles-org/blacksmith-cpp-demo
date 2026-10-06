#include "libs/signals/signal.h"

namespace signals {

double Signal161(const Ticks& ticks) {
  return Evaluate<161, 112>(ticks) + Evaluate<1161, 112>(ticks);
}

}
