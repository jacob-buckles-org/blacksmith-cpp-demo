#include "libs/signals/signal.h"

namespace signals {

double Signal094(const Ticks& ticks) {
  return Evaluate<94, 112>(ticks) + Evaluate<1094, 112>(ticks);
}

}
