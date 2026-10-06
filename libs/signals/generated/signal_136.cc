#include "libs/signals/signal.h"

namespace signals {

double Signal136(const Ticks& ticks) {
  return Evaluate<136, 112>(ticks) + Evaluate<1136, 112>(ticks);
}

}
