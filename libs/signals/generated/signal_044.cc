#include "libs/signals/signal.h"

namespace signals {

double Signal044(const Ticks& ticks) {
  return Evaluate<44, 112>(ticks) + Evaluate<1044, 112>(ticks);
}

}
