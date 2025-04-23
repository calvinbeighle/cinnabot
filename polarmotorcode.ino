#include <Stepper.h>

const int stepsPerRevolution = 2048; // 28BYJ-48

// Motor pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// Limit switch pin
#define LIMIT_SWITCH_PIN 14

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(115200);
  pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);
  myStepper.setSpeed(10); // Slightly faster speed for calibration

  calibrateStepper(); // Calibrate at start

  myStepper.setSpeed(5); // Back to normal operational speed
}

void loop() {
  Serial.println("Moving one revolution clockwise...");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  Serial.println("Moving one revolution counterclockwise...");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}

// Calibration function (homing to limit switch)
void calibrateStepper() {
  Serial.println("Calibrating stepper (homing)...");

  // Rotate counterclockwise until limit switch is pressed
  while (digitalRead(LIMIT_SWITCH_PIN) == HIGH) {
    myStepper.step(-10); // Small incremental steps counterclockwise
    delay(5); // Short delay for stability
  }

  Serial.println("Limit switch activated! Setting home position.");
  delay(500); // Wait briefly after homing

  // Move slightly away from switch to disengage it
  myStepper.step(50);
  delay(500);

  Serial.println("Calibration complete.");
}
