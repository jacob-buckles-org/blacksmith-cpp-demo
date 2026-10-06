#include "libs/signals/signal.h"

namespace signals {

double Signal157(const Ticks& ticks) {
  return Evaluate<157, 112>(ticks) + Evaluate<1157, 112>(ticks);
}

}
