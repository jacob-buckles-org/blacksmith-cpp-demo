#include "libs/signals/signal.h"

namespace signals {

double Signal196(const Ticks& ticks) {
  return Evaluate<196, 112>(ticks) + Evaluate<1196, 112>(ticks);
}

}
