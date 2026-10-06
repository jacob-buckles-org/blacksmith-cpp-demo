#include "libs/signals/signal.h"

namespace signals {

double Signal029(const Ticks& ticks) {
  return Evaluate<29, 112>(ticks) + Evaluate<1029, 112>(ticks);
}

}
