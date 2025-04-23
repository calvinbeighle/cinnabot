#pragma once
#include <AccelStepper.h>
#include "V_seq.h"              // the table

class VibrationSweep {
  AccelStepper& st;
  uint16_t i              = 0;                        // current index
  const uint16_t N        = sizeof(R_SEQ)/sizeof(R_SEQ[0]);

  // helper: pull one float from flash
  static float getR(uint16_t idx) {
    return pgm_read_float_near(R_SEQ + idx);
  }

public:
  explicit VibrationSweep(AccelStepper& s) : st(s) {}

  void begin() { st.moveTo(lround(getR(i))); }

  void run() {
    if (st.distanceToGo() == 0) {             
      if (++i == N) i = 0;                    
      st.moveTo(lround(getR(i)));             
    st.run();
  }
};
