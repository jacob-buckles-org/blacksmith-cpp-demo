#include "libs/signals/signal.h"

namespace signals {

double Signal179(const Ticks& ticks) {
  return Evaluate<179, 112>(ticks) + Evaluate<1179, 112>(ticks);
}

}
