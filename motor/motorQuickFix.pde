#include "Servo.h"

#define MOTOR_PIN_RIGHT 2
#define MOTOR_PIN_LEFT 3
#define MOTOR_PIN_FRONT 5
#define MOTOR_PIN_REAR 6

#define MIN_THROTTLE 1000
#define MAX_THROTTLE 2000
#define IDLE_THROTTLE 1100


/*Objects for the ESCs are created here, will be used to control motor speed*/
Servo escRight;
Servo escLeft;
Servo escFront;
Servo escRear;

void setup(void){

    /*Attach correct motor pin to corresponding ESC object*/
    escRight.attach(MOTOR_PIN_RIGHT);
    escLeft.attach(MOTOR_PIN_LEFT);
    escFront.attach(MOTOR_PIN_FRONT);
    escRear.attach(MOTOR_PIN_REAR);
    
    /*a delay to get time to connect batteries*/
    //delay(10000);
    
    /*Calibrate the motors*/
    /*set throttle level to max*/
    //escRight.write(MAX_THROTTLE);
    //escLeft.write(MAX_THROTTLE);
    //escFront.write(MAX_THROTTLE);
    //escRear.write(MAX_THROTTLE);
    //delay(5000);
    
    /*set throttle level to min*/
    escRight.write(MIN_THROTTLE);
    escLeft.write(MIN_THROTTLE);
    escFront.write(MIN_THROTTLE);
    escRear.write(MIN_THROTTLE);
    delay(15000);
    
    /*go!!!*/
    //moto_run();   
}

void loop(void){
    /*while loop will get motor speed to idle up and down*/
    while(1){
        escRight.write(IDLE_THROTTLE);
        escLeft.write(IDLE_THROTTLE);
        escFront.write(IDLE_THROTTLE);
        escRear.write(IDLE_THROTTLE);
        
        delay(5000);
        
        escRight.write(IDLE_THROTTLE+100);
        escLeft.write(IDLE_THROTTLE+100);
        escFront.write(IDLE_THROTTLE+100);
        escRear.write(IDLE_THROTTLE+100);
        
        delay(5000);
    }
}
