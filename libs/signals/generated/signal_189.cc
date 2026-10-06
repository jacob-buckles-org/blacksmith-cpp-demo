#include "libs/signals/signal.h"

namespace signals {

double Signal189(const Ticks& ticks) {
  return Evaluate<189, 112>(ticks) + Evaluate<1189, 112>(ticks);
}

}
