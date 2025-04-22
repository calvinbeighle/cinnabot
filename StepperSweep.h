#pragma once
#include <AccelStepper.h>

class StepperSweep {
  AccelStepper& st;
  long distance;
  uint8_t flips;                       // two flips = one full cycle
public:
  // cycles = number of complete back‑and‑forth sweeps
  StepperSweep(AccelStepper& s, long dist, uint8_t cycles)
      : st(s), distance(dist), flips(cycles * 2) {}

  void begin()               { st.moveTo(distance); }

  void run() {
    if (flips && st.distanceToGo() == 0) {
      st.moveTo(-st.currentPosition());  // reverse
      --flips;
    }
    st.run();
  }
};
