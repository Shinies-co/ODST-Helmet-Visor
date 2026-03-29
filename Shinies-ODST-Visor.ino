#include <Servo.h>

// =====================================================
// CHANGE THESE VALUES IF NEEDED
// =====================================================
const int BUTTON_PIN = 2;          // Button wire goes here
const int SERVO_PIN  = 9;          // Servo signal wire goes here

const int CLOSED_ANGLE = 5;        // Visor fully closed position
const int OPEN_ANGLE   = 75;       // Visor fully open position

const bool REVERSE_SERVO = true;   // Set to true if the servo moves backwards
const bool HOLD_POSITION = true;   // true = servo stays locked, false = servo releases after moving

const int STEP_DELAY_MS    = 10;    // Lower = faster movement
const int STARTUP_DELAY_MS = 1000; // Wait after powering on
const int HOLD_TIME_MS     = 800;  // Hold button this long to force visor closed
const int SETTLE_TIME_MS   = 250;  // Extra time after movement finishes

const int OVERSHOOT_ANGLE  = 3;    // Extra push past final position before settling back

// Safety limits
const int MIN_SAFE_ANGLE = 0;
const int MAX_SAFE_ANGLE = 180;

// =====================================================
// DO NOT CHANGE BELOW UNLESS YOU WANT TO CUSTOMIZE MORE
// =====================================================
Servo visorServo;

bool visorIsOpen = false;

bool lastButtonReading = HIGH;
unsigned long buttonPressStart = 0;
bool holdActionTriggered = false;

// Keep angle in a safe range
int clampAngle(int angle) {
  if (angle < MIN_SAFE_ANGLE) return MIN_SAFE_ANGLE;
  if (angle > MAX_SAFE_ANGLE) return MAX_SAFE_ANGLE;
  return angle;
}

// Handles reversed servo direction if needed
int getServoAngle(int angle) {
  angle = clampAngle(angle);

  if (REVERSE_SERVO) {
    return 180 - angle;
  }

  return angle;
}

// Make sure servo is attached before moving
void ensureServoAttached() {
  if (!visorServo.attached()) {
    visorServo.attach(SERVO_PIN);
  }
}

// Release servo only if HOLD_POSITION is false
void releaseServoIfNeeded() {
  if (!HOLD_POSITION && visorServo.attached()) {
    visorServo.detach();
  }
}

// Smooth servo movement
void moveServoSmooth(int fromAngle, int toAngle) {
  fromAngle = clampAngle(fromAngle);
  toAngle   = clampAngle(toAngle);

  ensureServoAttached();

  if (fromAngle < toAngle) {
    for (int angle = fromAngle; angle <= toAngle; angle++) {
      visorServo.write(getServoAngle(angle));
      delay(STEP_DELAY_MS);
    }
  } else {
    for (int angle = fromAngle; angle >= toAngle; angle--) {
      visorServo.write(getServoAngle(angle));
      delay(STEP_DELAY_MS);
    }
  }

  delay(SETTLE_TIME_MS);
  releaseServoIfNeeded();
}

// Open visor
void openVisor() {
  ensureServoAttached();

  // Push slightly past the final angle
  visorServo.write(getServoAngle(OPEN_ANGLE + 3));
  delay(200);

  // Settle back to final angle
  visorServo.write(getServoAngle(OPEN_ANGLE));
  delay(SETTLE_TIME_MS);

  releaseServoIfNeeded();
  visorIsOpen = true;
}

// Close visor
void closeVisor() {
  ensureServoAttached();

  visorServo.write(getServoAngle(clampAngle(CLOSED_ANGLE - OVERSHOOT_ANGLE)));
  delay(200);

  visorServo.write(getServoAngle(CLOSED_ANGLE));
  delay(SETTLE_TIME_MS);

  releaseServoIfNeeded();
  visorIsOpen = false;
}

// Toggle visor
void toggleVisor() {
  if (visorIsOpen) {
    closeVisor();
  } else {
    openVisor();
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  ensureServoAttached();
  visorServo.write(getServoAngle(CLOSED_ANGLE));
  delay(STARTUP_DELAY_MS);

  visorIsOpen = false;
  releaseServoIfNeeded();
}

void loop() {
  bool buttonReading = digitalRead(BUTTON_PIN);

  // Button pressed
  if (lastButtonReading == HIGH && buttonReading == LOW) {
    buttonPressStart = millis();
    holdActionTriggered = false;
  }

  // Button being held
  if (buttonReading == LOW && !holdActionTriggered) {
    if (millis() - buttonPressStart >= HOLD_TIME_MS) {
      closeVisor();              // Hold button to force visor closed
      holdActionTriggered = true;
    }
  }

  // Button released
  if (lastButtonReading == LOW && buttonReading == HIGH) {
    unsigned long pressLength = millis() - buttonPressStart;

    // Normal press = toggle visor
    if (!holdActionTriggered && pressLength > 20) {
      toggleVisor();
    }
  }

  lastButtonReading = buttonReading;
}