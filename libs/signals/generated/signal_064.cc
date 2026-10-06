#include "libs/signals/signal.h"

namespace signals {

double Signal064(const Ticks& ticks) {
  return Evaluate<64, 112>(ticks) + Evaluate<1064, 112>(ticks);
}

}
