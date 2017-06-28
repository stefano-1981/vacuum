#include "tests.h"

#include <iostream>

std::vector<std::pair<void(*)(), std::string>>* GetTests() {
  static auto* tests = new std::vector<std::pair<void(*)(), std::string>>();
  return tests;
}

TestRunner::TestRunner(void(*f)(), const std::string& name) {
  std::vector<std::pair<void(*)(), std::string>>* tests = GetTests();

  tests->emplace_back(f, name);
}

/* static */
void TestRunner::run() {
  std::cout << "Running: " << GetTests()->size() << " tests." << std::endl;
  for (auto f : *GetTests()) {
    std::cout << "Running test: " << f.second << std::endl;
    f.first();
  }
}

