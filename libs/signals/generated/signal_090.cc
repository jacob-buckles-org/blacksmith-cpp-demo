#include "libs/signals/signal.h"

namespace signals {

double Signal090(const Ticks& ticks) {
  return Evaluate<90, 112>(ticks) + Evaluate<1090, 112>(ticks);
}

}
