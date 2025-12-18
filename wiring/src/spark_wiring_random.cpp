#include "spark_wiring_random.h"
#include <stdlib.h>

/**
 * @brief Generate random number from 0 to max-1
 * @param max Upper bound (exclusive)
 * @return Random number in range [0, max)
 */
int random(int max)
{
    if (max <= 0)
    {
        return 0;
    }
    // Validate max is reasonable to prevent overflow
    if (max > 2147483647) {
        return 0;
    }
  return rand() % max;
}

int random(int min, int max)
{
  if (min >= max) {
    return min;
  }
  // Validate range is reasonable
  if ((max - min) > 2147483647 || (max - min) < 0) {
      return min;
  }
  return random(max - min) + min;
}

void randomSeed(unsigned int seed)
{
  srand(seed);
}

