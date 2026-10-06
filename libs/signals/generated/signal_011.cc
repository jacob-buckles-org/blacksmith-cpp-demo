#include "libs/signals/signal.h"

namespace signals {

double Signal011(const Ticks& ticks) {
  return Evaluate<11, 112>(ticks) + Evaluate<1011, 112>(ticks);
}

}
