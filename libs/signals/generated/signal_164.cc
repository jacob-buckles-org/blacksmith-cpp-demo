#include "libs/signals/signal.h"

namespace signals {

double Signal164(const Ticks& ticks) {
  return Evaluate<164, 112>(ticks) + Evaluate<1164, 112>(ticks);
}

}
