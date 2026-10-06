#include "libs/signals/signal.h"

namespace signals {

double Signal097(const Ticks& ticks) {
  return Evaluate<97, 112>(ticks) + Evaluate<1097, 112>(ticks);
}

}
