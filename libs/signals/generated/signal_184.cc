#include "libs/signals/signal.h"

namespace signals {

double Signal184(const Ticks& ticks) {
  return Evaluate<184, 112>(ticks) + Evaluate<1184, 112>(ticks);
}

}
