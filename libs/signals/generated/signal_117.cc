#include "libs/signals/signal.h"

namespace signals {

double Signal117(const Ticks& ticks) {
  return Evaluate<117, 112>(ticks) + Evaluate<1117, 112>(ticks);
}

}
