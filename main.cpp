#include "mbed.h"
#include "DebouncedIn.h"
DebouncedIn button(PTB0);
DigitalIn button(PTB0);
DigitalOut Buzzer(PTB1);
DigitalOut Haptic(PTC1);
PwmOut LED_R(PTB2);
PwmOut LED_G(PTB3);
PwmOut LED_B(PTC2);

PwmOut ledPWM(PTE20);

void PWM_OK()
{

    ledPWM.period(0.01f);
    ledPWM = 0.0f;



    for(float val = 0.0f; val < 1.0f; val += 0.02f) {
        ledPWM = val;
        wait(0.005f);
    }

    for(float val = 1.0f; val > 0.0f; val -= 0.02f ) {
        ledPWM = val;
        wait(0.005f);
    }

}


void PWM_WARNING()
{

    ledPWM.period(0.01f);
    ledPWM = 0.0f;



    for(float val = 0.0f; val < 1.0f; val += 0.02f) {
        ledPWM = val;
        wait(0.005f);
    }

    for(float val = 1.0f; val > 0.0f; val -= 0.02f ) {
        ledPWM = val;
        wait(0.005f);
    }

}


void PWM_ERROR()
{

    ledPWM.period(0.01f);
    ledPWM = 0.0f;



    for(float val = 0.0f; val < 1.0f; val += 0.02f) {
        ledPWM = val;
        wait(0.005f);
    }

    for(float val = 1.0f; val > 0.0f; val -= 0.02f ) {
        ledPWM = val;
        wait(0.005f);
    }

}

void PWM_BUSY()
{

    ledPWM.period(0.01f);
    ledPWM = 0.0f;



    for(float val = 0.0f; val < 1.0f; val += 0.02f) {
        ledPWM = val;
        wait(0.005f);
    }

    for(float val = 1.0f; val > 0.0f; val -= 0.02f ) {
        ledPWM = val;
        wait(0.005f);
    }

}

int i=0;



int main()
{

    //DebouncedIn button(PTB0);
    //DigitalOut LED(PTB1);
    //PwmOut LED(PTB1);

    typedef enum {OK,WARNING,ERROR,BUSY} state_t;
    static state_t next_state, current_state;
    current_state = OK;

    while (true) {

        if (button.rising())
            current_state = next_state;

        switch (current_state) {
            case OK:
                LED_B = 0;
                LED_R = 0;

                wait_ms(100);
                //LED = 0;
                // wait_ms(1000);
                LED_G = 1;

                
                i=i++;
                if(i<2) {
                    Buzzer = 1;
                    Haptic = 1;
                    wait_ms(100);
                    Buzzer = 0;
                    Haptic = 0;
                    wait_ms(100);
                    Buzzer = 1;
                    Haptic = 1;
                    wait_ms(100);
                    Buzzer = 0;
                    Haptic = 0;
                    PWM_OK();
                }


                next_state = WARNING;
                break;
            case WARNING:
                LED_R = 0;
                LED_G = 0;

                
                i=0;
                wait_ms(50);
                LED_B = 0;
                Buzzer = 0;
                Haptic = 0;
                wait_ms(50);
                LED_B = 1;
                Buzzer = 1;
                Haptic = 1;
                wait_ms(50);
                LED_B = 0;
                Buzzer = 0;
                Haptic = 0;
                wait_ms(50);
                LED_B = 1;
                Buzzer = 1;
                Haptic = 1;
                wait_ms(50);
                LED_B = 0;
                Buzzer = 0;
                Haptic = 0;
                wait_ms(700);
                LED_B = 1;
                Buzzer = 1;
                Haptic = 1;
                wait_ms(50);
                LED_B = 0;
                Buzzer = 0;
                Haptic = 0;
                
               
                PWM_WARNING();

                next_state = ERROR;
                break;
            case ERROR:
                LED_B = 0;
                LED_G = 0;

                PWM_ERROR();
                wait_ms(50);
                LED_R = 0;
                Buzzer = 0;
                Haptic = 0;
                PWM_ERROR();
                wait_ms(50);
                LED_R = 1;
                Buzzer = 1;
                Haptic = 1;
                next_state = BUSY;

                break;
            case BUSY:
                /*wait_ms(500);
                LED = 0;
                wait_ms(500);
                LED = 1;*/
                PWM_BUSY();
                wait_ms(40);
                LED_B = 0;
                LED_G = 0;
                LED_R = 0;
                Buzzer = 0;
                Haptic = 0;
                wait_ms(40);

                LED_B = 1;
                LED_G = 1;
                LED_R = 1;
                Buzzer = 1;
                Haptic = 1;
                wait_ms(40);

                LED_B = 0;
                LED_G = 0;
                LED_R = 0;

                Buzzer = 0;
                Haptic = 0;
                wait_ms(40);

                LED_B = 1;
                LED_G = 1;
                LED_R = 1;
                Buzzer = 0;
                Haptic = 0;
                wait_ms(150);

                next_state = OK;

                break;
            default:
                break;

        }
    }
}

/*
void PWM(void)
{
    while(button != 1) {

        //SERVO

        LED.period(0.005f);
        LED = 0.0f;
        // if(button == 1) break ;
        for(float val = 0.0f; val < 1.0f; val += 0.07f) {
            LED = val;
            //Buzzer = val;
            //Servo
            if(button == 1) break ;
            wait(0.05f);
        }
        // if(button == 1) break ;
        for(float val = 1.0f; val > 0.0f; val -= 0.07f ) {
            LED = val;
            //Buzzer = val;
            if(button == 1) break ;
            wait(0.05f);
        }
        if(button == 1) break ;
    }
}

*/