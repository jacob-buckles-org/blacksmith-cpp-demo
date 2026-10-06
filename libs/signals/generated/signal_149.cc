#include "libs/signals/signal.h"

namespace signals {

double Signal149(const Ticks& ticks) {
  return Evaluate<149, 112>(ticks) + Evaluate<1149, 112>(ticks);
}

}
