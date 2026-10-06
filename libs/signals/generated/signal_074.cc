#include "libs/signals/signal.h"

namespace signals {

double Signal074(const Ticks& ticks) {
  return Evaluate<74, 112>(ticks) + Evaluate<1074, 112>(ticks);
}

}
