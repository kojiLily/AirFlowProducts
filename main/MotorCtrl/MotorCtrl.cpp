#include "Arduino.h"
#include "MotorCtrl.h"


MotorCtrl::MotorCtrl(){
    m_pin=m_pwm=0;
}
void MotorCtrl::set(int pin_value,int pwm_value,boolean led_value){

    m_pin=pin_value;
    m_pwm=pwm_value;
    m_led=led_value;
}

void MotorCtrl::initialize(void){
    m_pwm=0;
}

void MotorCtrl::move(){
    analogWrite(m_pin,m_pwm);
}

void MotorCtrl::setPWM(int value){
    m_pwm=value;
}

void MotorCtrl::setLED(boolean led_value){
    m_led=led_value;
}

boolean MotorCtrl::getLED(){
    return m_led;
}

