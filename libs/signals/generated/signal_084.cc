#include "libs/signals/signal.h"

namespace signals {

double Signal084(const Ticks& ticks) {
  return Evaluate<84, 112>(ticks) + Evaluate<1084, 112>(ticks);
}

}
