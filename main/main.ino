const int IN1=5;
const int OUT1=6;
const byte READPIN=A0;
uint8_t speeds=200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int readValue(void){
  return int(analogRead(READPIN));
}

void pwmMotor(int In,int Out){
  analogWrite(IN1,In);
  analogWrite(OUT1,Out);
}

void loop() {
  int value = map(readValue(), 0, 1023, 0, 255); //(0-1024)-->(0-255)

  Serial.print("analog_value:");
  Serial.println(value);

  if(value<5)//モータを停止させる
  {
    pwmMotor(256,256);
    delay(50);
  }
  else
  {//モータを正転する
    pwmMotor(0,value);
    delay(50);
  }
}
