#include "utils.h"

#include <cstdlib>
#include <ctime>

float Random() {
  static unsigned int* seed = new unsigned int(time(0));
  return static_cast <float> (rand_r(seed)) / static_cast <float> (RAND_MAX);
}
