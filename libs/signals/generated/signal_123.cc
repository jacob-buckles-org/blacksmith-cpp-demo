#include "libs/signals/signal.h"

namespace signals {

double Signal123(const Ticks& ticks) {
  return Evaluate<123, 112>(ticks) + Evaluate<1123, 112>(ticks);
}

}
