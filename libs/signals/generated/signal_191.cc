#include "libs/signals/signal.h"

namespace signals {

double Signal191(const Ticks& ticks) {
  return Evaluate<191, 112>(ticks) + Evaluate<1191, 112>(ticks);
}

}
