#include "libs/signals/signal.h"

namespace signals {

double Signal073(const Ticks& ticks) {
  return Evaluate<73, 112>(ticks) + Evaluate<1073, 112>(ticks);
}

}
