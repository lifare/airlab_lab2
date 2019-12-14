#include "Wire.h"
#include <Arduino.h>
#include "button.h"

#define PIN_BUTTON 5
#define WAIT 3

Button button_make(PIN_BUTTON);

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
    if (button_make.wasPressed())
        Wire.write(WAIT);
}
