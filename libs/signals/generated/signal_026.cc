#include "libs/signals/signal.h"

namespace signals {

double Signal026(const Ticks& ticks) {
  return Evaluate<26, 112>(ticks) + Evaluate<1026, 112>(ticks);
}

}
