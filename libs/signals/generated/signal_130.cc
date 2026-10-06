#include "libs/signals/signal.h"

namespace signals {

double Signal130(const Ticks& ticks) {
  return Evaluate<130, 112>(ticks) + Evaluate<1130, 112>(ticks);
}

}
