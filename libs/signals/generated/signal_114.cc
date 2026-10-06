#include "libs/signals/signal.h"

namespace signals {

double Signal114(const Ticks& ticks) {
  return Evaluate<114, 112>(ticks) + Evaluate<1114, 112>(ticks);
}

}
