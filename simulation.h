#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "agent.h"
#include "battery.h"
#include "map.h"

// Manages the simulation.
class Simulation {
 public:
  // Builds a simulation on a certain map.
  explicit Simulation(const Map& map);

  // Run the simulation until there is no time or the agent is dead.
  void Run();

  // Returns the agent score.
  float GetAgentScore();

 private:
  // The time left in the simulation. The agent has only read access to this
  // object.
  int time_left_;

  // The agent battery. The agent has only read access to this object.
  Battery battery_;

  // The agent of the simulation.
  Agent agent_;

  // The map where the simulation happens.
  Map map_;
};

#endif  // SIMULATION_H_
