#include "libs/signals/signal.h"

namespace signals {

double Signal119(const Ticks& ticks) {
  return Evaluate<119, 112>(ticks) + Evaluate<1119, 112>(ticks);
}

}
