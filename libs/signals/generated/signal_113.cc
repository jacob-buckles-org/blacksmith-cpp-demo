#include "libs/signals/signal.h"

namespace signals {

double Signal113(const Ticks& ticks) {
  return Evaluate<113, 112>(ticks) + Evaluate<1113, 112>(ticks);
}

}
