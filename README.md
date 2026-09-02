# Smart Glove 🧤

A wearable ESP32 project that uses five flex sensors to recognize finger gestures and send the detected gesture over Bluetooth.

## Project goal
Turn hand gestures into digital commands. The first version focuses on reliable finger-bend detection; more gestures can be added after collecting real sensor data.

## Hardware
- ESP32 development board
- 5 × flex sensors
- 5 × 10kΩ resistors
- Breadboard + jumper wires
- Glove
- Optional: MPU6050 for hand orientation/motion

## Flex-sensor wiring
Each flex sensor is used as a voltage divider:
- One side of the flex sensor → 3.3V
- Other side → ESP32 analog pin
- 10kΩ resistor from that analog pin → GND

Default analog pins in the example:
- Thumb: GPIO 34
- Index: GPIO 35
- Middle: GPIO 32
- Ring: GPIO 33
- Pinky: GPIO 25

## Important
The exact sensor thresholds depend on your individual glove. Open Serial Monitor, record the values for straight and bent fingers, and adjust the thresholds in `smart_glove.ino`.

## Bluetooth
The ESP32 creates a Bluetooth Serial device named `SmartGlove`. A phone or computer can connect and receive detected gesture text.

## Suggested next upgrades
1. Add MPU6050 orientation sensing.
2. Add a calibration button.
3. Collect gesture samples and train a small classifier.
4. Create a phone app that converts recognized gestures to speech.
5. Add an OLED display for the detected word.

## How to present it
Be honest about which features are completed. If speech, MPU6050, or machine learning is not implemented yet, describe them as future improvements rather than completed features.
