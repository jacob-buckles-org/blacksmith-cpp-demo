#include "libs/signals/signal.h"

namespace signals {

double Signal121(const Ticks& ticks) {
  return Evaluate<121, 112>(ticks) + Evaluate<1121, 112>(ticks);
}

}
