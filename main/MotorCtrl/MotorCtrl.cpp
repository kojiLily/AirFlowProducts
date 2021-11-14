#include "Arduino.h"
#include "MotorCtrl.h"

MotorCtrl::MotorCtrl(int pin_value,int pwm_value){

    m_pin=pin_value;
    m_pwm=pwm_value;
}

void MotorCtrl::initialize(void){
    m_pwm=0;
}

void MotorCtrl::move(int value){
    digitalWrite(m_pin,value);
}

void MotorCtrl::set(int value){
    m_pwm=value;
}

