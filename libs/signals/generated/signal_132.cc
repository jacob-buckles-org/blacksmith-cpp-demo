#include "libs/signals/signal.h"

namespace signals {

double Signal132(const Ticks& ticks) {
  return Evaluate<132, 112>(ticks) + Evaluate<1132, 112>(ticks);
}

}
