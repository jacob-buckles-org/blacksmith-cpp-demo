#include "libs/signals/signal.h"

namespace signals {

double Signal120(const Ticks& ticks) {
  return Evaluate<120, 112>(ticks) + Evaluate<1120, 112>(ticks);
}

}
