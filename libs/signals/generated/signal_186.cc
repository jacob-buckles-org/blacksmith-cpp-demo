#include "libs/signals/signal.h"

namespace signals {

double Signal186(const Ticks& ticks) {
  return Evaluate<186, 112>(ticks) + Evaluate<1186, 112>(ticks);
}

}
