#include "libs/signals/signal.h"

namespace signals {

double Signal175(const Ticks& ticks) {
  return Evaluate<175, 112>(ticks) + Evaluate<1175, 112>(ticks);
}

}
