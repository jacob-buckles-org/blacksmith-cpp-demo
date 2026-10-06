#include "libs/signals/signal.h"

namespace signals {

double Signal039(const Ticks& ticks) {
  return Evaluate<39, 112>(ticks) + Evaluate<1039, 112>(ticks);
}

}
