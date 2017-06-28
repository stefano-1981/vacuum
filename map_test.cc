#include "map.h"

#include <cassert>
#include <vector>

#include "tests.h"

TEST(Map_AgentCannotMove) {
  Map map(3, 3);
  // The agent is in the only free position, (1, 1);
  assert(map.AgentPosition() == Point({1, 1}));
  for (const Direction d : std::vector<Direction>{Direction::UP,
        Direction::DOWN,
        Direction::LEFT,
        Direction::RIGHT}) {
    map.Update(d);
    // Agent does not go anywhere.
    assert(map.AgentPosition() == Point({1, 1}));
  }
}

TEST(Map_CleanDirt) {
  Map map(5, 5);
  assert(map.AgentPosition() == Point({1, 1}));
  map.SetDirt(2, 2);
  map.SetDirtCount();
  assert(map.CleanedRatio() == 0);

  map.Update(Direction::DOWN);
  assert(map.CleanedRatio() == 0);
  map.Update(Direction::RIGHT);
  assert(map.CleanedRatio() == 0);
  map.Update(Direction::NONE);
  assert(map.CleanedRatio() == 1);
}
