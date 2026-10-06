#include "libs/signals/signal.h"

namespace signals {

double Signal118(const Ticks& ticks) {
  return Evaluate<118, 112>(ticks) + Evaluate<1118, 112>(ticks);
}

}
