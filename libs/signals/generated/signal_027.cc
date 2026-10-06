#include "libs/signals/signal.h"

namespace signals {

double Signal027(const Ticks& ticks) {
  return Evaluate<27, 112>(ticks) + Evaluate<1027, 112>(ticks);
}

}
