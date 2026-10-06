#include "libs/signals/signal.h"

namespace signals {

double Signal182(const Ticks& ticks) {
  return Evaluate<182, 112>(ticks) + Evaluate<1182, 112>(ticks);
}

}
