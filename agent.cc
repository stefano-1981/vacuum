// Copyright 2017 Stefano Pellegrini

#include "agent.h"

#include "utils.h"

Agent::Agent(const Battery* battery, const int* time) :
  battery_(battery), time_(time) {}

Direction Agent::NextDirection(const Perception& p) {
  const float random = Random();
  if (random < 0.2) {
    return Direction::NONE;
  }
  if (random < 0.4) {
    return Direction::LEFT;
  }
  if (random < 0.6) {
    return Direction::UP;
  }
  if (random < 0.8) {
    return Direction::DOWN;
  }
  return Direction::RIGHT;
}

bool Agent::IsAlive() const {
  return battery_->Level() > 0;
}
