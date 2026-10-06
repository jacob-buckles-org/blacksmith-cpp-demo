#include "libs/signals/signal.h"

namespace signals {

double Signal085(const Ticks& ticks) {
  return Evaluate<85, 112>(ticks) + Evaluate<1085, 112>(ticks);
}

}
