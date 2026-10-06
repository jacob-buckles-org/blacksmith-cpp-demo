#include "libs/signals/signal.h"

namespace signals {

double Signal053(const Ticks& ticks) {
  return Evaluate<53, 112>(ticks) + Evaluate<1053, 112>(ticks);
}

}
