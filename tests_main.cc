// Runs all the tests.

#include <iostream>

#include "tests.h"

int main() {
  //  std::cout << TestRunner::tests_.size() << std::endl;
  TestRunner tests;
  tests.run();
  std::cout << "All tests ran successfully!!" << std::endl;
}
