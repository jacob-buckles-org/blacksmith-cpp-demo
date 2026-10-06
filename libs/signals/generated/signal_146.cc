#include "libs/signals/signal.h"

namespace signals {

double Signal146(const Ticks& ticks) {
  return Evaluate<146, 112>(ticks) + Evaluate<1146, 112>(ticks);
}

}
