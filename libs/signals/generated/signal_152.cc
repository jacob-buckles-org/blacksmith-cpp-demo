#include "libs/signals/signal.h"

namespace signals {

double Signal152(const Ticks& ticks) {
  return Evaluate<152, 112>(ticks) + Evaluate<1152, 112>(ticks);
}

}
