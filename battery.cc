#include "battery.h"

Battery::Battery(int initial_level) : level_(initial_level) {
  if (level_ < 0) {
    level_ = 0;
  }
}

void Battery::Charge() {
  ++level_;
}

int Battery::Level() const { return level_; }

void Battery::Use() {
  --level_;
  if (level_ < 0) {
    level_ = 0;
  }
}
