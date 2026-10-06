#include "libs/signals/signal.h"

namespace signals {

double Signal144(const Ticks& ticks) {
  return Evaluate<144, 112>(ticks) + Evaluate<1144, 112>(ticks);
}

}
