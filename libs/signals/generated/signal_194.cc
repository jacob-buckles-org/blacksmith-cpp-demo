#include "libs/signals/signal.h"

namespace signals {

double Signal194(const Ticks& ticks) {
  return Evaluate<194, 112>(ticks) + Evaluate<1194, 112>(ticks);
}

}
