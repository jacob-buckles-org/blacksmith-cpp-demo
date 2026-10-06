#include "libs/signals/signal.h"

namespace signals {

double Signal172(const Ticks& ticks) {
  return Evaluate<172, 112>(ticks) + Evaluate<1172, 112>(ticks);
}

}
