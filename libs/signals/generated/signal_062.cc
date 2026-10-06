#include "libs/signals/signal.h"

namespace signals {

double Signal062(const Ticks& ticks) {
  return Evaluate<62, 112>(ticks) + Evaluate<1062, 112>(ticks);
}

}
