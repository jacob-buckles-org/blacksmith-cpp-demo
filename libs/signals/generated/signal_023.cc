#include "libs/signals/signal.h"

namespace signals {

double Signal023(const Ticks& ticks) {
  return Evaluate<23, 112>(ticks) + Evaluate<1023, 112>(ticks);
}

}
