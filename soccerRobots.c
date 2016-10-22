#include <Servo.h>
Servo leftservo;
Servo rightservo;


int tx = 1;     // output on pin 1 from the Bluetooth
int rx = 0;     // input on pin 0 from the Bluetooth 
char inStr[15];   // char array holding input string 
int i = 0; //  index for char array 

// sets up the pin modes for each 
void setup(){  
  Serial.begin(9600);

// servos attached to pin 10 and 11
  leftservo.attach(10);
  rightservo.attach(11);
  
  leftservo.write(91); // have both servos static
  rightservo.write(90);

  pinMode(tx, OUTPUT); // setting functionality Bluetooth
  pinMode(rx, INPUT);
}
// the loop will run over and over while the arduino is on 
void loop(){

    delay(20);
   
    
    //gets input from bluetooth
    if (Serial.available() > 0) {    // Serial.available() returns available input in rx pin.      
        
       while (Serial.available() > 0) {
         delay(20);    
         inStr[i] = Serial.read();     // Serial.read() stores a char at a time in string 
         i++;      
        } // end of while

       inStr[i]='\0';
       i=0;  // reset i for next round around the loop 
       
      Serial.println(inStr);
      
      if(!strcmp(inStr,"f")){   // front arrow == forward
            leftservo.write(135);
            rightservo.write(45);

       }
        else if(!strcmp(inStr,"X")){   // X == forward
            leftservo.write(135);
            rightservo.write(45);
       }
        if(!strcmp(inStr,"T")){  // triangle == backwards 
            leftservo.write(45);
            rightservo.write(135);

       }else if (!strcmp(inStr,"O")){ // stop
            leftservo.write(91);
            rightservo.write(90);
       
       }else if (!strcmp(inStr,"b")){ // back arrow == backwards
            leftservo.write(45);
            rightservo.write(135);

       } else if (!strcmp(inStr,"l")){ //left arrow == left

        leftservo.write(100);
        rightservo.write(45);
           
       }else if (!strcmp(inStr,"r")){ // right arrow == right

        leftservo.write(135);
        rightservo.write(80); 
       }else if(!strcmp(inStr,"4")){ // square == stop  
            leftservo.write(91);
            rightservo.write(90);
       }else if(!strcmp(inStr,"S")){  // start = go ; 
            leftservo.write(135);
            rightservo.write(45);
       }else if(!strcmp(inStr,"s")){   // select = stop
            leftservo.write(91);
            rightservo.write(90);
       }
       
    } // ends read input
}