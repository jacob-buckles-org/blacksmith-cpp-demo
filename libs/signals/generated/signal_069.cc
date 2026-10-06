#include "libs/signals/signal.h"

namespace signals {

double Signal069(const Ticks& ticks) {
  return Evaluate<69, 112>(ticks) + Evaluate<1069, 112>(ticks);
}

}
