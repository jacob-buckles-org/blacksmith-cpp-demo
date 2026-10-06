#include "libs/signals/signal.h"

namespace signals {

double Signal028(const Ticks& ticks) {
  return Evaluate<28, 112>(ticks) + Evaluate<1028, 112>(ticks);
}

}
