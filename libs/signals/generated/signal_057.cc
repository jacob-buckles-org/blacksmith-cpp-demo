#include "libs/signals/signal.h"

namespace signals {

double Signal057(const Ticks& ticks) {
  return Evaluate<57, 112>(ticks) + Evaluate<1057, 112>(ticks);
}

}
