#include "libs/signals/signal.h"

namespace signals {

double Signal105(const Ticks& ticks) {
  return Evaluate<105, 112>(ticks) + Evaluate<1105, 112>(ticks);
}

}
