#include "libs/signals/signal.h"

namespace signals {

double Signal059(const Ticks& ticks) {
  return Evaluate<59, 112>(ticks) + Evaluate<1059, 112>(ticks);
}

}
