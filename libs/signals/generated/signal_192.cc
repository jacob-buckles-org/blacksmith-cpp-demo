#include "libs/signals/signal.h"

namespace signals {

double Signal192(const Ticks& ticks) {
  return Evaluate<192, 112>(ticks) + Evaluate<1192, 112>(ticks);
}

}
