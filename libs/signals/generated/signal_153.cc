#include "libs/signals/signal.h"

namespace signals {

double Signal153(const Ticks& ticks) {
  return Evaluate<153, 112>(ticks) + Evaluate<1153, 112>(ticks);
}

}
