#include "libs/signals/signal.h"

namespace signals {

double Signal103(const Ticks& ticks) {
  return Evaluate<103, 112>(ticks) + Evaluate<1103, 112>(ticks);
}

}
