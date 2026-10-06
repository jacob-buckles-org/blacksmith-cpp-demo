#include "libs/signals/signal.h"

namespace signals {

double Signal042(const Ticks& ticks) {
  return Evaluate<42, 112>(ticks) + Evaluate<1042, 112>(ticks);
}

}
