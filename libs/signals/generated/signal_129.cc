#include "libs/signals/signal.h"

namespace signals {

double Signal129(const Ticks& ticks) {
  return Evaluate<129, 112>(ticks) + Evaluate<1129, 112>(ticks);
}

}
