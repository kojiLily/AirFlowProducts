#include"MotorCtrl/MotorCtrl.h"

const int DIN_PIN=8;//8番ピンをボタンの状態，読み取りとして定義
const int PWM_PIN[4]={5,6,9,10};//PWM対応のpinを設定
const int LED_PIN[4]={4,7,8,12};//点灯LEDのpinを設定
const byte READPIN = A0;
MotorCtrl motor[4];//モータごとにインスタンスを定義

void setup() {
  // put your setup code here, to run once:
  pinMode( DIN_PIN, INPUT );
  Serial.begin(9600);
  

  //全モータのPWM_PINを設定し，valueをすべて0に初期化する．
  for(int i=0;i<4;i++){
    motor[i].set(PWM_PIN[i],0,false);
  }
  motor[0].set(PWM_PIN[0],0,true);
  
}

int readValue(void) {
  return int(analogRead(READPIN));
}

void allClear(){
  for(int i=0;i<4;i++){
    digitalWrite(LED_PIN[i],LOW);
  }
}

void writeLED(int led_pin){
  allClear();
  digitalWrite(LED_PIN[led_pin],HIGH);
}

int j=0;
void loop() {

  int value = map(readValue(), 0, 1023, 0, 255); //(0-1024)-->(0-255)

  Serial.print("analog_value:");
  Serial.println(value);

  if(digitalRead(DIN_PIN)!=0){
    //もし，ボタンが押されていたら，次の後続モータに選択状態を移行し，現在の選択を解除する．
    //現在のモータのLEDの状態をLEDをfalseに設定，後続モータの状態をtrueに設定し，loopに戻る
    motor[j++].setLED(false);
    if(j>=4){
      j=0;
    }
    motor[j].setLED(true);
    delay(50);
  }

  //現在のモータのpwm値をsetし続けて，選択状態にあるモータのLEDを点灯する．
  motor[j].setPWM(value);
  
  for(int i=0;i<4;i++){
    if(motor[i].getLED()!=false){
      //選択されているモータのLEDを光らせる
      //暫定は，各リード線で光ることを確認-->シフトレジスタで管理
      writeLED(i);

    }
  }

  //全モータを稼働
  for(int i=0;i<4;i++){
    motor[i].move();
  }
}
