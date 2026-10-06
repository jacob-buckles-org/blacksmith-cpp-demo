#include "libs/signals/signal.h"

namespace signals {

double Signal045(const Ticks& ticks) {
  return Evaluate<45, 112>(ticks) + Evaluate<1045, 112>(ticks);
}

}
