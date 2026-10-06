#include "libs/signals/signal.h"

namespace signals {

double Signal187(const Ticks& ticks) {
  return Evaluate<187, 112>(ticks) + Evaluate<1187, 112>(ticks);
}

}
