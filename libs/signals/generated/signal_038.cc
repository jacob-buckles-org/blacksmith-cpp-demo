#include "libs/signals/signal.h"

namespace signals {

double Signal038(const Ticks& ticks) {
  return Evaluate<38, 112>(ticks) + Evaluate<1038, 112>(ticks);
}

}
