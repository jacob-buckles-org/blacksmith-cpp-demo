#include "libs/signals/signal.h"

namespace signals {

double Signal154(const Ticks& ticks) {
  return Evaluate<154, 112>(ticks) + Evaluate<1154, 112>(ticks);
}

}
