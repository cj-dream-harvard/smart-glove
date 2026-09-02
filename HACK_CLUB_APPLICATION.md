## Hack Club application answer

One of the technical projects I’m most proud of is my Smart Glove, a wearable device I built to recognize hand gestures and turn them into digital commands.

I used an ESP32 and five flex sensors mounted on a glove to measure how much each finger bends. I programmed the ESP32 to read the sensor values, compare them with calibrated thresholds, recognize different combinations of finger positions, and send the detected gesture over Bluetooth.

The hardest part was making the recognition reliable. Sensor readings changed depending on how the glove was worn and how much a finger was bent, so I had to test real readings, choose useful thresholds, and debug the detection logic instead of assuming the sensor values would always be the same.

I’m proud of this project because it combines electronics, programming and a real physical interface. It also showed me how much iteration is involved in turning an idea into something that actually works. My next goal is to add motion sensing and a phone interface so recognized gestures can be converted into speech.
