#include "libs/signals/signal.h"

namespace signals {

double Signal067(const Ticks& ticks) {
  return Evaluate<67, 112>(ticks) + Evaluate<1067, 112>(ticks);
}

}
