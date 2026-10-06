#include "libs/signals/signal.h"

namespace signals {

double Signal080(const Ticks& ticks) {
  return Evaluate<80, 112>(ticks) + Evaluate<1080, 112>(ticks);
}

}
