#define DETECT 3 // sensor input jekono pin e hobe
#define ACTION A5 //jekono pin dewa jabe kaj kore kina


void setup() {
  Serial.begin(9600);
  pinMode(DETECT, INPUT);//define detect input pin
  pinMode(ACTION, OUTPUT);//define output pin

}

void loop() {

  int detected = digitalRead(DETECT);// read Laser sensor
 
  if( detected == HIGH)
  {
    digitalWrite(ACTION,HIGH);// set the action
    Serial.println("Detected!");

  }else{
    digitalWrite(ACTION,LOW); // Set the action stop
    Serial.println("No laser");

  }
  delay(200);
}
