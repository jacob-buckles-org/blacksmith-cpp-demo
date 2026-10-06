#include "libs/signals/signal.h"

namespace signals {

double Signal111(const Ticks& ticks) {
  return Evaluate<111, 112>(ticks) + Evaluate<1111, 112>(ticks);
}

}
