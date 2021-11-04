const int IN1=10;
const int OUT1=11;
const byte READPIN=A0;
uint8_t speeds=200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int readValue(void){
  return int(analogRead(READPIN));
}

void loop() {
  int value=map(readValue(),0,1023,255);//(0-1024)-->(0-255)

  Serial.print("analog_value:");
  Serial.println("value");

  if(value<5)//モータを停止させる
  {
    analogWrite(IN1,256);
    analogWrite(OUT1,256);
    delay(50);
  }
  else
  {//モータを正転する
    analogWrite(IN1,0);
    analogWrite(OUT1,speeds);
    delay(50);
  }
}
