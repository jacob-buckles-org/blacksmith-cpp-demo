#include "libs/signals/signal.h"

namespace signals {

double Signal089(const Ticks& ticks) {
  return Evaluate<89, 112>(ticks) + Evaluate<1089, 112>(ticks);
}

}
