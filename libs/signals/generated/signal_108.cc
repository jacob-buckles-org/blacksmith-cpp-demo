#include "libs/signals/signal.h"

namespace signals {

double Signal108(const Ticks& ticks) {
  return Evaluate<108, 112>(ticks) + Evaluate<1108, 112>(ticks);
}

}
