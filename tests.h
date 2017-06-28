#ifndef TESTS_H_
#define TESTS_H_

// Unit test infrastructure. To add unit tests include this class and do:
//
// TEST(SomeNameYouLike) {
//   the contents of your tests.
//   like assert(x == y);
// }

#include "battery.h"

#include <string>
#include <vector>

struct TestRunner {
 public:
  TestRunner() {}
  explicit TestRunner(void(*f)(), const std::string& test_name);

  void run();
};

#define TEST(NAME)                                    \
  void NAME();                                        \
  static TestRunner NAME##_runner(&NAME, #NAME);      \
  void NAME()

#endif  // TESTS_H_
