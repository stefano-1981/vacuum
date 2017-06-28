#ifndef BATTERY_H_
#define BATTERY_H_

// The battery of the agent.
class Battery {
 public:
  // Creates a battery with an initial capacity level.
  explicit Battery(int initial_level);

  // Charges the battery by one unit.
  void Charge();

  // Read the battery level.
  int Level() const;

  // Reduces the battery level by one unit.
  void Use();

 private:
  int level_;
};

#endif  // BATTERY_H_
