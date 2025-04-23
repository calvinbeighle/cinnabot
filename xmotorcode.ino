//is working!!

#include <AccelStepper.h>
#include "RadialSweep.h"            // ← was "xclass.h"

const int dirPin  = 16;
const int stepPin = 17;
#define motorInterfaceType 1
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

//  create the sweep object
RadialSweep sweep(myStepper);       // ← was: xclass sweep(myStepper, 200, 5);

void setup() {
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(200);

  sweep.begin();                    // unchanged
}

void loop() {
  sweep.run();                      // unchanged
}
