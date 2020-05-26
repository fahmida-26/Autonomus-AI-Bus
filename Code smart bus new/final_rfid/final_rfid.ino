#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8
#include <Servo.h>

#define laser 2 // laser sensor input jekono pin e kora jabe


Servo myservo;  // create servo object to control a servo



 char bt='S';
 int card=0; //jatri probesh bahir
 int count=0; //seat er shonkha count korbe
 int stopage=0;
 
MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
   myservo.attach(4);
   myservo.write(25);
  pinMode(laser, INPUT);//define detect input pin
  
  SPI.begin();
  rfid.PCD_Init();
  
  
}

void loop() {
  
  
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

  if(strID.indexOf("A1:2E:5E:79") >= 0  && count==0){
      count++;
      //servo door open close code
      myservo.write(150);                  // sets the servo position according to the scaled value
      delay(1500);          
      Serial.println("Sim Sim Khulja");
      myservo.write(25); 
       Serial.println(count);
    }
   else if(strID.indexOf("B0:4D:8E:28") >= 0  && card==0){
      card++;
      //servo door open close code
      myservo.write(150);                  // sets the servo position according to the scaled value
      delay(1500);          
      Serial.println("Sim Sim Khulja");
      myservo.write(25); 
       Serial.println(count);
    }
        //strID.indexOf("B0:4D:8E:28") >= 0)
        
  else if(strID.indexOf("A1:2E:5E:79") >= 0 && card!=0){
      // eita main card...second bar punch korar por bill dekhabe
     
      Serial.println("Seat Full");
    }
    else if(strID.indexOf("B0:4D:8E:28") >= 0  && count!=0){
      
      Serial.println("Seat Full");
      }
    else if(strID.indexOf("B0:4D:8E:28") >= 0 && card!=0){
      // eita main card...second bar punch korar por bill dekhabe
      card=0;
      //servo door open close code
      myservo.write(150);                  // sets the servo position according to the scaled value
      delay(1500);          
      
      Serial.println("Your Bill 20taka Has been Deducted");
      Serial.println("Sim Sim Khulja");
      myservo.write(25); 
       Serial.println(count);
      }
      else if(strID.indexOf("A1:2E:5E:79") >= 0 && card!=0){
      // eita main card...second bar punch korar por bill dekhabe
      count=0;
      //servo door open close code
      myservo.write(150);                  // sets the servo position according to the scaled value
      delay(1500);          
      
      Serial.println("Your Bill 20taka Has been Deducted");
      Serial.println("Sim Sim Khulja");
      myservo.write(25); 
       Serial.println(count);
      }
 
  }
