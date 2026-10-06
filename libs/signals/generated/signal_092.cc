#include "libs/signals/signal.h"

namespace signals {

double Signal092(const Ticks& ticks) {
  return Evaluate<92, 112>(ticks) + Evaluate<1092, 112>(ticks);
}

}
