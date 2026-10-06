#include "libs/signals/signal.h"

namespace signals {

double Signal014(const Ticks& ticks) {
  return Evaluate<14, 112>(ticks) + Evaluate<1014, 112>(ticks);
}

}
