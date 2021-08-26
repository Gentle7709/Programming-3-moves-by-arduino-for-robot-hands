//________________________________________________________
#include <Servo.h>
Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo

int Button = 5 ; 
int startPos = 90;    
int state = 0 ;
int old = 0 ; 
int ButtonPoll = 0;
//________________________________________________________

void setup() {
  
pinMode(Button , INPUT) ;  
  
servo1.attach(3);  
servo2.attach(11); 
servo1.write(startPos); 
servo2.write(startPos); 
delay(5000); 
  
}

void loop() {
ButtonPoll = digitalRead(Button);
  if(ButtonPoll == 1 ){
    delay(50) ; 
    ButtonPoll = digitalRead(Button);
    if( ButtonPoll == 0){
      state = old +1 ; 
    }
  }

else {
  delay(100); 
}
switch(state) {
  case 1: 
  servo1.write(60);
  servo2.write(60);
  old = state ; 
  break ;
  case 2: 
  servo1.write(90);
  servo2.write(90);
  delay(100);
  old = state ;
  break;
  case 3: 
  servo1.write(180);
  servo2.write(180);
  delay(100);
  old = state ; 
  break ; 
  default:
  servo1.write(0);
  servo2.write(0);
  delay(100);
  old = 0 ;
  break;
}



  

}
