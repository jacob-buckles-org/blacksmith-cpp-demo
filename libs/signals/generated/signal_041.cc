#include "libs/signals/signal.h"

namespace signals {

double Signal041(const Ticks& ticks) {
  return Evaluate<41, 112>(ticks) + Evaluate<1041, 112>(ticks);
}

}
