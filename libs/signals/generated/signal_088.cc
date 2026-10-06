#include "libs/signals/signal.h"

namespace signals {

double Signal088(const Ticks& ticks) {
  return Evaluate<88, 112>(ticks) + Evaluate<1088, 112>(ticks);
}

}
