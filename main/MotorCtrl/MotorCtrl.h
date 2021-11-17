#ifndef MOTOR_CTRL_h
    #define MOTOR_CTRL_h

    #include"Arduino.h"

    class MotorCtrl
    {
    public:
        MotorCtrl();
        void initialize(void);
        void move();
        void setPWM(int value);
        void setLED(boolean led_value);
        void set(int pin_value,int pwm_value,boolean led_value);
        boolean getLED();

    private:
        int m_pin; //クラス内で使用するpin
        int m_pwm; //クラス内で使用するpwm値
        boolean m_led;//選択されているLEDを点灯するための変数
    };
#endif
