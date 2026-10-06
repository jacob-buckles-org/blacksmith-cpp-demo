#include "libs/signals/signal.h"

namespace signals {

double Signal124(const Ticks& ticks) {
  return Evaluate<124, 112>(ticks) + Evaluate<1124, 112>(ticks);
}

}
