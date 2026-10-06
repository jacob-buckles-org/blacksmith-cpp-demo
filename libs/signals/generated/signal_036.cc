#include "libs/signals/signal.h"

namespace signals {

double Signal036(const Ticks& ticks) {
  return Evaluate<36, 112>(ticks) + Evaluate<1036, 112>(ticks);
}

}
