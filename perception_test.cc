#include "perception.h"

#include <cassert>
#include <cmath>

#include "tests.h"

TEST(Perception_SetGetSignal) {
  Perception p;
  p.SetChargingSignal(0.1);
  assert(fabs(p.GetChargingSignal() - 0.1) < 1e-6);
}

TEST(Perception_SetGetObstacles_Invalid) {
  Perception p;

  assert(!p.HasObstacle(Direction::UP));
  p.SetObstacle(Direction::UP);
  assert(p.HasObstacle(Direction::UP));

  assert(!p.HasObstacle(Direction::DOWN));
  p.SetObstacle(Direction::DOWN);
  assert(p.HasObstacle(Direction::DOWN));

  assert(!p.HasObstacle(Direction::LEFT));
  p.SetObstacle(Direction::LEFT);
  assert(p.HasObstacle(Direction::LEFT));

  assert(!p.HasObstacle(Direction::RIGHT));
  p.SetObstacle(Direction::RIGHT);
  assert(p.HasObstacle(Direction::RIGHT));
}
