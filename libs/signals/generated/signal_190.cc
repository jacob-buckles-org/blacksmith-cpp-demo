#include "libs/signals/signal.h"

namespace signals {

double Signal190(const Ticks& ticks) {
  return Evaluate<190, 112>(ticks) + Evaluate<1190, 112>(ticks);
}

}
