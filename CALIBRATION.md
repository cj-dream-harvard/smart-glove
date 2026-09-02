# Smart Glove Calibration

1. Upload `smart_glove.ino`.
2. Temporarily uncomment the `Serial.printf(...)` line near the bottom.
3. Open Arduino Serial Monitor at 115200 baud.
4. Keep each finger straight and record the five values.
5. Bend each finger and record the values again.
6. Choose thresholds between the straight and bent readings.
7. Replace the five `THRESH_...` values in the sketch.
8. Test every gesture several times.
9. If your sensor value gets smaller when bent, change `bent()` from:
   `return value > threshold;`
   to:
   `return value < threshold;`
