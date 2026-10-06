#include "libs/signals/signal.h"

namespace signals {

double Signal055(const Ticks& ticks) {
  return Evaluate<55, 112>(ticks) + Evaluate<1055, 112>(ticks);
}

}
