#include "libs/signals/signal.h"

namespace signals {

double Signal024(const Ticks& ticks) {
  return Evaluate<24, 112>(ticks) + Evaluate<1024, 112>(ticks);
}

}
