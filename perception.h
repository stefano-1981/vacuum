#ifndef PERCEPTION_H_
#define PERCEPTION_H_

#include <map>

#include "geometry.h"

// The perception of the agent.
class Perception {
 public:
  Perception();

  // Returns whether there is an obstacle in this direction.
  bool HasObstacle(const Direction d) const;

  // Returns the signal at the perception point.
  float GetChargingSignal() const;

  // Sets the obstacle value.
  void SetObstacle(const Direction d);

  // Sets the signal of the charging station.
  void SetChargingSignal(float signal);

 private:
  std::map<Direction, bool> obstacles_;
  float charging_signal_;
};

#endif  // PERCEPTION_H_
