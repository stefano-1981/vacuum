// Copyright 2017 Stefano Pellegrini

#include "perception.h"


Perception::Perception() : charging_signal_(0)
{}

void Perception::SetObstacle(const Direction d) {
  obstacles_[d] = true;
}

void Perception::SetChargingSignal(float signal) {
  charging_signal_ = signal;
}

bool Perception::HasObstacle(const Direction d) const {
  auto it = obstacles_.find(d);
  if (it == obstacles_.end()) {
    return false;
  }
  return it->second;
}

float Perception::GetChargingSignal() const {
  return charging_signal_;
}
