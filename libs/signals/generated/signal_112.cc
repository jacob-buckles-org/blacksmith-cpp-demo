#include "libs/signals/signal.h"

namespace signals {

double Signal112(const Ticks& ticks) {
  return Evaluate<112, 112>(ticks) + Evaluate<1112, 112>(ticks);
}

}
