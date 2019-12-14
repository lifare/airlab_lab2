#include <Arduino.h>
#include "Wire.h"
#include "Servo.h"

const int address = 10;
bool make_turn;
Servo servo1;

void setup() {
  servo1.attach(5);
  servo1.write(0);
  Wire.begin(address);
  Serial.begin(115200);
  Wire.onReceive(handle_receive);
  make_turn = false;
}

void loop() {
  if (make_turn){
    int time_wait = Wire.read()*1000;
    servo1.write(180);
    delay(time_wait);
    servo1.write(0);
    make_turn = false;
  }
}

void handle_receive(){
  if (Wire.available())
    make_turn = true;
}
