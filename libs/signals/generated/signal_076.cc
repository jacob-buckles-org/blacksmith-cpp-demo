#include "libs/signals/signal.h"

namespace signals {

double Signal076(const Ticks& ticks) {
  return Evaluate<76, 112>(ticks) + Evaluate<1076, 112>(ticks);
}

}
