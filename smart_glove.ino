#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Flex sensor analog pins
const int FLEX_THUMB  = 34;
const int FLEX_INDEX  = 35;
const int FLEX_MIDDLE = 32;
const int FLEX_RING   = 33;
const int FLEX_PINKY  = 25;

// Change these after calibration.
// A flex sensor's value can increase OR decrease when bent,
// depending on how it is wired.
const int THRESH_THUMB  = 2200;
const int THRESH_INDEX  = 2200;
const int THRESH_MIDDLE = 2200;
const int THRESH_RING   = 2200;
const int THRESH_PINKY  = 2200;

unsigned long lastGestureTime = 0;
const unsigned long gestureDelay = 700;

int readFlex(int pin) {
  return analogRead(pin);
}

bool bent(int value, int threshold) {
  return value > threshold;
}

String detectGesture(int t, int i, int m, int r, int p) {
  bool bt = bent(t, THRESH_THUMB);
  bool bi = bent(i, THRESH_INDEX);
  bool bm = bent(m, THRESH_MIDDLE);
  bool br = bent(r, THRESH_RING);
  bool bp = bent(p, THRESH_PINKY);

  // Example gestures. Recalibrate thresholds for your glove.
  if (!bt && !bi && !bm && !br && !bp) return "OPEN_HAND";
  if (bt && bi && bm && br && bp) return "FIST";
  if (!bt && bi && bm && br && bp) return "THUMBS_UP";
  if (bt && !bi && !bm && br && bp) return "PEACE";
  if (bt && !bi && !bm && !br && !bp) return "POINT";

  return "UNKNOWN";
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("SmartGlove");

  analogReadResolution(12);

  Serial.println("Smart Glove started.");
  Serial.println("Connect to Bluetooth device: SmartGlove");
}

void loop() {
  int t = readFlex(FLEX_THUMB);
  int i = readFlex(FLEX_INDEX);
  int m = readFlex(FLEX_MIDDLE);
  int r = readFlex(FLEX_RING);
  int p = readFlex(FLEX_PINKY);

  String gesture = detectGesture(t, i, m, r, p);

  // Send only after a short delay so the same gesture isn't spammed.
  if (gesture != "UNKNOWN" &&
      millis() - lastGestureTime > gestureDelay) {

    Serial.println(gesture);
    SerialBT.println(gesture);

    lastGestureTime = millis();
  }

  // Uncomment during calibration:
  // Serial.printf("T:%d I:%d M:%d R:%d P:%d\n", t, i, m, r, p);

  delay(50);
}
