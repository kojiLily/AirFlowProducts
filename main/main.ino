#include"MotorCtrl/MotorCtrl.h"

const int IN1 = 5;
const int IN2 = 6;
const byte READPIN = A0;
uint8_t speeds = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int readValue(void) {
  return int(analogRead(READPIN));
}

void pwmMotor(int In) {
  analogWrite(IN1, In);
  analogWrite(IN2, In / 2);
  //analogWrite(OUT1,Out);
}

void loop() {
  int value = map(readValue(), 0, 1023, 0, 255); //(0-1024)-->(0-255)

  Serial.print("analog_value:");
  Serial.println(value);


}
