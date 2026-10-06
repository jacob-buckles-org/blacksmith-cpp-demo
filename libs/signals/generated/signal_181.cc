#include "libs/signals/signal.h"

namespace signals {

double Signal181(const Ticks& ticks) {
  return Evaluate<181, 112>(ticks) + Evaluate<1181, 112>(ticks);
}

}
