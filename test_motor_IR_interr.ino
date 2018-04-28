/* 
This is the code for the pidestal, it uses the adafruit motorshield v2.3. I am currently revising this so be nice
*/
#include <Adafruit_MotorShield.h>
const int sens = 7;
const int red = 11;  //assign red normally open button to pin 12
const int blue = 12; //assign blue normally open button to pin 11
int valr=0;
int valb=0;
int vals=0;
int trg=0;
int brun=1;
int rrun=1;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();   // Create the motor shield object with the default I2C address
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);         //Sets a motor at motor port 1

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
  AFMS.begin();        // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
 
  myMotor->run(RELEASE);//cuts power to motor in setup loop

  pinMode(red, INPUT);  
  pinMode(blue, INPUT); 
 pinMode(sens, INPUT); 
 digitalWrite(blue, HIGH);
 digitalWrite(red, HIGH);
 
}

const int x = 100; //int value used to define motor speed, small impulses are aroun 5/10, max speed is 225 *personal note, 100 is extremely fast. 

void loop() {
       valr=digitalRead(red);
       valb=digitalRead(blue);
       vals=digitalRead(sens);
  if (digitalRead(sens)==1){
          trg=1;}
      if(digitalRead(red) == LOW){   
       if (trg==1){
        trg=0;
        rrun=0;
        brun=1;
       }
       if (rrun==1){
        brun=1;
       trg=0;
        myMotor->run(FORWARD); //runs your motor "forward", make sure you test what forward is so you dont destoy anything expensive
        myMotor->setSpeed(x); } //sets motor speed to constant integer value defined outside of loop 
      
        else {
           myMotor->setSpeed(0);
        }
      }
      else if(digitalRead(blue )== LOW){ 
           if (trg==1){
        trg=0;
        rrun=1;
        brun=0;
       }
       if (brun==1){
        rrun=1;
        trg=0;
        myMotor->run(BACKWARD); //Well I mean I guess this one runs the motor backwards 
        myMotor->setSpeed(x); }  //what does it MEEEEAAAAN
      
        else {
          myMotor->setSpeed(0);
        }
      }
    else {
    myMotor->setSpeed(0);}
   
    
      delay(10); //wait 10 miliseconds to restart this loop
//Serial.println(valr);
//Serial.println(valb);
Serial.println(vals); }
 

