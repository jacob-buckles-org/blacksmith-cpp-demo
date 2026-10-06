#include "libs/signals/signal.h"

namespace signals {

double Signal102(const Ticks& ticks) {
  return Evaluate<102, 112>(ticks) + Evaluate<1102, 112>(ticks);
}

}
