#include "libs/signals/signal.h"

namespace signals {

double Signal072(const Ticks& ticks) {
  return Evaluate<72, 112>(ticks) + Evaluate<1072, 112>(ticks);
}

}
