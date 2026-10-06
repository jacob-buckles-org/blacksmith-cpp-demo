#include "libs/signals/signal.h"

namespace signals {

double Signal155(const Ticks& ticks) {
  return Evaluate<155, 112>(ticks) + Evaluate<1155, 112>(ticks);
}

}
