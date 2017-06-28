#include "simulation.h"

#include <iostream>

Simulation::Simulation(const Map& map) : time_left_(100),
                                         battery_(100),
                                         agent_(&battery_, &time_left_),
                                         map_(map) {}
void Simulation::Run() {
  while (time_left_ > 0 && agent_.IsAlive()) {
    // Get the agent action based on the perception.
    const Perception& perception = map_.GetAgentPerception();
    Direction action = agent_.NextDirection(perception);

    // Update all things.
    map_.Update(action);
    if (map_.AgentAtHome()) {
      battery_.Charge();
    }

    --time_left_;
    battery_.Use();

    map_.Print();
  }
}

float Simulation::GetAgentScore() {
  float score = map_.CleanedRatio() * 0.5;
  std::cout << map_.CleanedRatio() << std::endl;
  if (map_.AgentAtHome()) {
    score += 0.5;
  }
  return score;
}
