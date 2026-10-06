#include "libs/signals/signal.h"

namespace signals {

double Signal050(const Ticks& ticks) {
  return Evaluate<50, 112>(ticks) + Evaluate<1050, 112>(ticks);
}

}
