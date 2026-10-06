#include "libs/signals/signal.h"

namespace signals {

double Signal150(const Ticks& ticks) {
  return Evaluate<150, 112>(ticks) + Evaluate<1150, 112>(ticks);
}

}
