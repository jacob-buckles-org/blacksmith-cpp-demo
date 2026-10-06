#include "libs/signals/signal.h"

namespace signals {

double Signal018(const Ticks& ticks) {
  return Evaluate<18, 112>(ticks) + Evaluate<1018, 112>(ticks);
}

}
