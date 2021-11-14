#ifndef MOTOR_CTRL_h
    #define MOTOR_CTRL_h

    #include"Arduino.h"

    class MotorCtrl
    {
    public:
        MotorCtrl(int pin_value,int pwm_value);//インスタンス
        void initialize(void);
        void move(int value);
        void set(int value);

    private:
        int m_pin; //クラス内で使用するpin
        int m_pwm; //クラス内で使用するpwm値
    };
#endif
