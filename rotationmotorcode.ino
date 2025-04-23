#include <AccelStepper.h>
#include "RadialSweep.h"               

// ---------- MOTOR --------------------
const int dirPin  = 16;
const int stepPin = 17;
#define motorInterfaceType 1
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);
RadialSweep sweep(myStepper);          // ← motor sweep object

// ---------- BUTTON -------------------
const int BUTTON_PIN = 13;             // GPIO 33 → one leg of button
bool lastState   = HIGH;               // INPUT_PULLUP idles HIGH
unsigned long lastReport = 0;          // periodic heartbeat
// -------------------------------------

void setup() {
  // Motor setup (unchanged)
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(200);
  sweep.begin();

  // Button / Serial setup
  Serial.begin(115200);
  Serial.println("Booting...");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // ----- run motor as before -----
  sweep.run();

  // ----- read button -----
  bool currentState = digitalRead(BUTTON_PIN);

  // immediate report on change (debounced)
  if (currentState != lastState) {
    Serial.println(currentState == LOW ? 1 : 0);
    lastState = currentState;
    delay(20);                           // simple debounce
  }

  // 1-second heartbeat so the monitor shows *something* even when idle
  if (millis() - lastReport >= 1000) {
    Serial.println(currentState == LOW ? 1 : 0);
    lastReport = millis();
  }
}
