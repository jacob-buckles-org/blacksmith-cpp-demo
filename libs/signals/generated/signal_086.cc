#include "libs/signals/signal.h"

namespace signals {

double Signal086(const Ticks& ticks) {
  return Evaluate<86, 112>(ticks) + Evaluate<1086, 112>(ticks);
}

}
