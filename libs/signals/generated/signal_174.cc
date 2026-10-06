#include "libs/signals/signal.h"

namespace signals {

double Signal174(const Ticks& ticks) {
  return Evaluate<174, 112>(ticks) + Evaluate<1174, 112>(ticks);
}

}
