#include "libs/signals/signal.h"

namespace signals {

double Signal156(const Ticks& ticks) {
  return Evaluate<156, 112>(ticks) + Evaluate<1156, 112>(ticks);
}

}
