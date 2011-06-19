#include "Servo.h"

#define MOTOR_PIN_RIGHT 2
#define MOTOR_PIN_LEFT 3
#define MOTOR_PIN_FRONT 5
#define MOTOR_PIN_REAR 6

#define MIN_THROTTLE 1000            //1000
#define MAX_THROTTLE 2000
#define IDLE_THROTTLE 1280        //1100 max1350

/*
Controllers
0 - All motors
1 - front 
2 - left 
3 - right
4 - back

*/



/*Objects for the ESCs are created here, will be used to control motor speed*/
Servo escRight;
Servo escLeft;
Servo escFront;
Servo escRear;


int in;	
int countDown;
int retF;
int retR;
int retL;
int retB;

void setup(void){
Serial.begin(9600);
    /*Attach correct motor pin to corresponding ESC object*/
    escRight.attach(MOTOR_PIN_RIGHT);
    escLeft.attach(MOTOR_PIN_LEFT);
    escFront.attach(MOTOR_PIN_FRONT);
    escRear.attach(MOTOR_PIN_REAR);
    
     
    /*set throttle level to min*/
    escRight.write(MIN_THROTTLE);
    escLeft.write(MIN_THROTTLE);
    escFront.write(MIN_THROTTLE);
    escRear.write(MIN_THROTTLE);
    /*
    10 sec delay to put in the batteries   
    */
    Serial.println("Put in the batteries");
    //for (countDown = 15;0 <= countDown ; countDown--){
    // Serial.println(countDown); 
   // delay(1000);
   // }
    delay(15000);
   
     Serial.println("Sarting");
     escRight.write(IDLE_THROTTLE);
     escLeft.write(IDLE_THROTTLE);
     escFront.write(IDLE_THROTTLE);
     escRear.write(IDLE_THROTTLE);
   delay(1000);
     
}

void loop(void){
  
  Serial.println("Can send data");
if (Serial.available() > 0) {
		// read the incoming byte:
		in = Serial.read();

		// say what you got:
		Serial.print("I received: ");
		Serial.println(in, DEC);
	
if(in==49){
 Serial.println("Front"); 
 Serial.println("Enter Speed"); 
 delay(1000);
retF = retInt();
Serial.print("Front received \t");
Serial.println(retF);
}

else if(in==50){
 Serial.println("Left"); 
 Serial.println("Enter Speed"); 
 delay(1000);
retL = retInt();
Serial.print("Left received \t");
Serial.println(retL); 
}
else if(in==51){
 Serial.println("Right"); 
 Serial.println("Enter Speed"); 
 delay(1000);
 retR = retInt();
 Serial.print("Right received \t");
 Serial.println(retR); 
}
else if(in==52){
 Serial.println("Back"); 
 Serial.println("Enter Speed"); 
 delay(1000);
 retB = retInt();
 Serial.print("Left received \t");
 Serial.println(retB); 
}
else if(in==48){
  Serial.println("All"); 
 Serial.println("Enter Speed"); 
 delay(1000);
retL = retInt();
retR = retInt();
retF = retInt();
retB = retInt();

Serial.print("All received \t");
Serial.println(retL); 
}
}   
        escRight.write(IDLE_THROTTLE+retR);
        escLeft.write(IDLE_THROTTLE+retL);
        escFront.write(IDLE_THROTTLE+retF);
        escRear.write(IDLE_THROTTLE+retB);    
        delay(1000);    
}

int retInt(void){
 
 int i,ser; 
 char speedo[5];
 char *inPtr = & speedo[0];
 ser = Serial.available();
 for (i = 0;i < ser;i++)  
 speedo[i]=Serial.read();
 speedo[i]='\0';
 return atoi(inPtr);
}
