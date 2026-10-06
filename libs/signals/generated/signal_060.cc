#include "libs/signals/signal.h"

namespace signals {

double Signal060(const Ticks& ticks) {
  return Evaluate<60, 112>(ticks) + Evaluate<1060, 112>(ticks);
}

}
