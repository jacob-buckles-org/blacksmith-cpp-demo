#include "libs/signals/signal.h"

namespace signals {

double Signal009(const Ticks& ticks) {
  return Evaluate<9, 112>(ticks) + Evaluate<1009, 112>(ticks);
}

}
