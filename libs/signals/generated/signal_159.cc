#include "libs/signals/signal.h"

namespace signals {

double Signal159(const Ticks& ticks) {
  return Evaluate<159, 112>(ticks) + Evaluate<1159, 112>(ticks);
}

}
