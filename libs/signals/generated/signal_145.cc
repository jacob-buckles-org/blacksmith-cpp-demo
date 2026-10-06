#include "libs/signals/signal.h"

namespace signals {

double Signal145(const Ticks& ticks) {
  return Evaluate<145, 112>(ticks) + Evaluate<1145, 112>(ticks);
}

}
