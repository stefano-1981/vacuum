#include "battery.h"

#include <cassert>

#include "tests.h"

TEST(BatteryChargeAndUse) {
  Battery b(1);
  assert(b.Level() == 1);
  b.Charge();
  assert(b.Level() == 2);
  b.Use();
  assert(b.Level() == 1);
  b.Use();
  assert(b.Level() == 0);
  b.Use();
  assert(b.Level() == 0);
}

TEST(BatteryInvalidInitialValue) {
  Battery b(-2);
  assert(b.Level() == 0);
}
