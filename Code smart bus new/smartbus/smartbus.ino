#include <AFMotor.h>
 int bt;

AF_DCMotor rmotor1(1);
AF_DCMotor rmotor2(2);
AF_DCMotor lmotor1(3);
AF_DCMotor lmotor2(4);

void setup() {
  Serial.begin(9600);
  //4,7,8,12     
  lmotor1.run(RELEASE);
  lmotor2.run(RELEASE);
  lmotor1.setSpeed(0);
  lmotor2.setSpeed(0);
  rmotor1.run(RELEASE);
  rmotor2.run(RELEASE);
  rmotor1.setSpeed(0);
  rmotor2.setSpeed(0);

}

void loop() {
  bt=Serial.read();
  if(bt='F'){
   forward();
  }
  if(bt='B'){
    backward();
  }
  if(bt='L'){
    left();
   }
 }
void backward(){
  lmotor1.run(FORWARD);
  lmotor2.run(FORWARD);
  rmotor1.run(FORWARD);
  rmotor2.run(FORWARD);
  lmotor1.setSpeed(150);
  lmotor2.setSpeed(150);
  rmotor1.setSpeed(150);
  rmotor2.setSpeed(150);
  }
void forward(){
  lmotor1.run(BACKWARD);
  lmotor2.run(BACKWARD);
  rmotor1.run(BACKWARD);
  rmotor2.run(BACKWARD);
  lmotor1.setSpeed(150);
  lmotor2.setSpeed(150);
  rmotor1.setSpeed(150);
  rmotor2.setSpeed(150);
   }
void right(){
  lmotor1.run(RELEASE);
  lmotor2.run(RELEASE);
  rmotor1.run(BACKWARD);
  rmotor2.run(BACKWARD);
  lmotor1.setSpeed(150);
  lmotor2.setSpeed(150);
  rmotor1.setSpeed(150);
  rmotor2.setSpeed(150);
  }
void left(){
  rmotor1.run(RELEASE);
  rmotor2.run(RELEASE);
  lmotor1.run(BACKWARD);
  lmotor2.run(BACKWARD);
  lmotor1.setSpeed(150);
  lmotor2.setSpeed(150);
  rmotor1.setSpeed(150);
  rmotor2.setSpeed(150);
  }
