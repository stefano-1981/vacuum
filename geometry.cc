#include "geometry.h"

#include <algorithm>
#include <cmath>
#include <iostream>

using std::cerr;
using std::vector;

bool Point::operator==(const Point& p) const {
  return p.x == x && p.y == y;
}

Point Point::operator+(const Point& p) const {
  return Point{x+p.x, y + p.y};
}

float Point::Distance(const Point& p) const {
  return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

Point DirectionToOffset(const Direction d) {
  switch (d) {
  case Direction::UP:
    return Point{0, 1};
  case Direction::DOWN:
    return Point{2, 1};
  case Direction::LEFT:
    return Point{1, 0};
  case Direction::RIGHT:
    return Point{1, 2};
  case Direction::NONE:
    return Point{1, 1};
  }
}

Direction OffsetToDirection(const Point& p) {
  if (p == Point{0, 1}) {
    return Direction::UP;
  }
  if (p == Point{2, 1}) {
    return Direction::DOWN;
  }
  if (p == Point{1, 0}) {
    return Direction::LEFT;
  }
  if (p == Point{1, 2}) {
    return Direction::RIGHT;
  }
  return Direction::NONE;
}

Matrix::Matrix(int x_size, int y_size) : x_size_(x_size), y_size_(y_size) {
  if (x_size_ < 0 || y_size_ < 0) {
    cerr << "Invalid matrix initialization with arguments: (" <<
      x_size << " " << y_size << "). Setting size to (0, 0)" << std::endl;
    x_size_ = 0;
    y_size_ = 0;
  }

  data_.resize(x_size * y_size, 0);
}

int Matrix::Get(int x, int y) const {
  return data_[x * y_size_ + y];
}

void Matrix::Set(int x, int y, int value) {
  data_[x * y_size_ + y] = value;
}

int Matrix::CountNonZero() const {
  return data_.size() - std::count(data_.begin(), data_.end(), 0);
}
