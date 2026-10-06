#include "libs/signals/signal.h"

namespace signals {

double Signal058(const Ticks& ticks) {
  return Evaluate<58, 112>(ticks) + Evaluate<1058, 112>(ticks);
}

}
