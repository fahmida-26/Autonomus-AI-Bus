#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8
#include <Servo.h>

#define laser 2 // laser sensor input jekono pin e kora jabe


Servo myservo;  // create servo object to control a servo


// connect motor controller pins to Arduino digital pins
// motor one
int enA = 3;
int in1 = 4;
int in2 = 5;
// motor two
int enB = 6;
int in3 = 7;
int in4 = 8;

 char bt='S';
 int card=0; //jatri probesh bahir
 int count=0; //seat er shonkha count korbe
 int stopage=0;
 
 int r1=A0;
 int r2=A1;
 int r3=A2;
 int r4=A3;

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
   myservo.attach(A0);
   
  pinMode(laser, INPUT);//define detect input pin
  
  SPI.begin();
  rfid.PCD_Init();
  
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  bt=Serial.read();

 int detected = digitalRead(laser);// read Laser sensor
 
  if( detected == HIGH) {
    digitalWrite(4,HIGH);// set the action
    Serial.println("Bus Stopage");
    stopage=1;

  }
  else{
    digitalWrite(4,LOW); // Set the action stop
    Serial.println("This is no bus stopage");
    stopage=0;
  }

  
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  Serial.print("Tap card key: ");
  Serial.println(strID);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  if(strID.indexOf("A1:2E:5E:79") >= 0 && count<=2 && card==0){
      // eita main card... but punch kora hoy nai
      card++;
      count++;
      //servo door open close code
      myservo.write(100);                  // sets the servo position according to the scaled value
      delay(500);          
      Serial.println("Sim Sim Khulja");
      myservo.write(0); 
    }
    else{Serial.println("Can not authorize.Please Register for Ticket");}
    
  if(strID.indexOf("A1:2E:5E:79") >= 0 && count<=2 && card==1){
      // eita main card...second bar punch korar por bill dekhabe
      count=count-1;
      card=0;
      Serial.println("Your bill 20taka only");
      //servo door open close code
      myservo.write(100);                  // sets the servo position according to the scaled value
      delay(500);          
      Serial.println("Sim Sim Khulja");
      myservo.write(0); 
    }
  if(strID.indexOf("A1:2E:5E:79") >= 0 && count==2 && card==0){
     Serial.println("No seat available");
    }
 
 if(bt=='F'){
     forward(); 
 } 
 else if(bt=='B'){
     backward(); 
 }
 else if(bt=='R'){
     right(); 
 }
 else if(bt=='L'){
     left(); 
 }
 else if(bt=='S' && stopage==1){
     Stop(); 
 }
 else if(bt=='S' && stopage==0){
     forward(); 
 }
}

void backward(){
   // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,255 );
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
  }
void forward(){
   // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,255 );
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
}
void right(){
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,255 );
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
  }
void left(){
   // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,255 );
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
  }
void Stop(){
   // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,0 );
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 0);
  }


