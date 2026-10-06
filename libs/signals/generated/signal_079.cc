#include "libs/signals/signal.h"

namespace signals {

double Signal079(const Ticks& ticks) {
  return Evaluate<79, 112>(ticks) + Evaluate<1079, 112>(ticks);
}

}
