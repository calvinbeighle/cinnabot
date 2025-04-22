#include <AccelStepper.h>
#include "StepperSweep.h"                  // ← NEW

const int dirPin  = 16;
const int stepPin = 17;
#define motorInterfaceType 1
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

// NEW: 200‑step travel, 5 complete cycles
StepperSweep sweep(myStepper, 200, 5);

void setup() {
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(200);

  sweep.begin();                           // ← NEW
}

void loop() {
  sweep.run();                             // ← NEW
}
