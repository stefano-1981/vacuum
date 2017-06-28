#include "geometry.h"

#include <cassert>

#include "tests.h"

TEST(Point_Equality) {
  const Point p1{1, 2};
  const Point p2{1, 2};
  const Point p3{0, 0};

  assert(p1 == p2);
  assert(p2 == p1);
  assert(!(p1 == p3));
  assert(!(p2 == p3));
}

TEST(Point_Sum) {
  const Point p1{-1, -2};
  const Point p2{1, 3};

  assert(Point({0, 1}) == (p1 + p2));
}

TEST(Matrix_InvalidInitialization) {
  Matrix(-2, -3);
}

TEST(Matrix_ValidInitialization) {
  Matrix m{10, 6};
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 6; ++y) {
      assert(m.Get(x, y) == 0);
    }
  }
}

TEST(Matrix_GetAndSet) {
  Matrix m{10, 6};
  m.Set(0, 0, 1);
  assert(m.Get(0, 0) == 1);
  m.Set(9, 5, -1);
  assert(m.Get(9, 5) == -1);
}

TEST(Matrix_CountNonZero) {
  Matrix m(3, 2);
  assert(m.CountNonZero() == 0);
  for (int i = 0; i < 3; ++i) {
    m.Set(1, 1, 2);
    assert(m.CountNonZero() == 1);
  }
  m.Set(1, 1, 0);
  assert(m.CountNonZero() == 0);

  m.Set(1, 1, 1);
  m.Set(1, 0, -2);
  assert(m.CountNonZero() == 2);
}
