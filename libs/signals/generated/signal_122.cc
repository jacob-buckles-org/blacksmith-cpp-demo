#include "libs/signals/signal.h"

namespace signals {

double Signal122(const Ticks& ticks) {
  return Evaluate<122, 112>(ticks) + Evaluate<1122, 112>(ticks);
}

}
