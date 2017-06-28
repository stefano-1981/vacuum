#ifndef GEOMETRY_H_
#define GEOMETRY_H_

// Copyright 2017 Stefano Pellegrini
//
// Geometric utilities.

#include <vector>

enum class Direction {
  NONE, LEFT, RIGHT, UP, DOWN
};

// A 2D point.
class Point {
 public:
  int x;
  int y;

  // Returns true if |p| has the same coordinates as this point.
  bool operator==(const Point& p) const;

  // Returns the sum of this point and |p|.
  Point operator+(const Point& p) const;

  // The distance to point |p|.
  float Distance(const Point& p) const;
};

// Converts the direction to an offset, and viceversa. The offset is the vector
// pointing to the direction |d| from the Point(1, 1) in a 3x3 matrix.
Point DirectionToOffset(Direction d);
Direction OffsetToDirection(const Point& p);

// A 2D integer matrix.
class Matrix {
 public:
  Matrix(int x_size, int y_size);

  int Get(int x, int y) const;

  void Set(int x, int y, int value);

  // Returns the number of non-zero elements in the matrix.
  int CountNonZero() const;

 private:
  int x_size_;
  int y_size_;
  std::vector<int> data_;
};

#endif  // GEOMETRY_H_
