#include "libs/signals/signal.h"

namespace signals {

double Signal021(const Ticks& ticks) {
  return Evaluate<21, 112>(ticks) + Evaluate<1021, 112>(ticks);
}

}
