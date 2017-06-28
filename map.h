#ifndef MAP_H_
#define MAP_H_

#include "geometry.h"
#include "perception.h"

// A map representing a room, with obstacles, dirt and the position of
// important objects.
class Map {
 public:
  // Builds a random map.
  static Map RandomMap(int x_size = 10, int y_size = 10);

  // Like the RandomMap(), but the map is divided in two rooms divided by a
  // narrow passage.
  static Map TwoRoomsMap(int x_size = 10, int y_size = 20);

  // Update the agent position. Note that if the agent tries to move
  // over a cell occupied by an obstacle, the move will have no
  // effect.
  bool Update(const Direction agent_action);

  // Returns the perception of the agent at the current agent position.
  Perception GetAgentPerception() const;

  // Returns true if the agent is at the charging stations.
  bool AgentAtHome() const;

  // Returns the ratio of dirt that has been removed wrt the original dirt.
  float CleanedRatio() const;

  // Prints the map, for debugging.
  void Print() const;

  // Returns the agent position.
  const Point& AgentPosition() const;

  // Creates an empty map with obstacles all around. Mostly for testing.
  explicit Map(int x_size, int y_size);

  // Sets an obstacle of value 1 at position (x, y).
  void SetObstacle(int x, int y);

  // Sets dirt of value 1 at position (x, y).
  void SetDirt(int x, int y);

  // Reset the dirt counter for cleaned ratio.
  void SetDirtCount();

 private:
  // Sets the agent and the charging stations to a free cell.
  bool InitAgentAndChargingStation();

  int x_size_;
  int y_size_;
  Point agent_position_;
  Point charging_station_;
  Matrix dirt_map_;
  Matrix obstacles_map_;
  int initial_dirt_;
};

#endif  // MAP_H_
