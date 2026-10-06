#include "libs/signals/signal.h"

namespace signals {

double Signal091(const Ticks& ticks) {
  return Evaluate<91, 112>(ticks) + Evaluate<1091, 112>(ticks);
}

}
