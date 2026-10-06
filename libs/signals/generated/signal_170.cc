#include "libs/signals/signal.h"

namespace signals {

double Signal170(const Ticks& ticks) {
  return Evaluate<170, 112>(ticks) + Evaluate<1170, 112>(ticks);
}

}
