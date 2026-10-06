#include "libs/signals/signal.h"

namespace signals {

double Signal173(const Ticks& ticks) {
  return Evaluate<173, 112>(ticks) + Evaluate<1173, 112>(ticks);
}

}
