#include "libs/signals/signal.h"

namespace signals {

double Signal148(const Ticks& ticks) {
  return Evaluate<148, 112>(ticks) + Evaluate<1148, 112>(ticks);
}

}
