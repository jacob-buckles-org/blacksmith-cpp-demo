#include "libs/signals/signal.h"

namespace signals {

double Signal070(const Ticks& ticks) {
  return Evaluate<70, 112>(ticks) + Evaluate<1070, 112>(ticks);
}

}
