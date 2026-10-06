#include "libs/signals/signal.h"

namespace signals {

double Signal012(const Ticks& ticks) {
  return Evaluate<12, 112>(ticks) + Evaluate<1012, 112>(ticks);
}

}
