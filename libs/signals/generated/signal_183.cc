#include "libs/signals/signal.h"

namespace signals {

double Signal183(const Ticks& ticks) {
  return Evaluate<183, 112>(ticks) + Evaluate<1183, 112>(ticks);
}

}
