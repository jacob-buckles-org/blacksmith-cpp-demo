#include "libs/signals/signal.h"

namespace signals {

double Signal098(const Ticks& ticks) {
  return Evaluate<98, 112>(ticks) + Evaluate<1098, 112>(ticks);
}

}
