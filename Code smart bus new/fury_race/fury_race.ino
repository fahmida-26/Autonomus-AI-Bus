// motor one
int enA = 3;
int in1 = 4;
int in2 = 5;
// motor two
int enB = 6;
int in3 = 7;
int in4 = 8;
// motor three
int enC = 3;
int in5 = 4;
int in6 = 5;
// motor four
int enD = 6;
int in7 = 7;
int in8 = 8;

void setup()
{
  //initlize the mode of the pins
   pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

   //set the serial communication rate
  Serial.begin(9600);
}

void loop()
{
  //check whether arduino is reciving signal or not 
  while(Serial.available() == 0);
  char val = Serial.read() ;//reads the signal
  Serial.print(val);

  /*********For Forward motion*********/
  
  if (val == 'F')
  {
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA,255 );
   digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB,255 );
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC,255 );
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD,255 );  
  
  }

 
    /*********For Backward Motion*********/
  else if(val == 'B')
  {
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA,255 );
   digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB,255 );
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC,255 );
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD,255 );
  }
   /*********RIGHT*********/
  else if(val == 'R')
  {
  Serial.println("right");
     digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,255 );
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
    digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enC,255 );
  // turn on motor B
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enD, 255);
  }
   /*********LEFT*********/
  else if(val == 'L')
  {
   
  Serial.println("left");
     digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA,255 );
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
    digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enC,255 );
  // turn on motor B
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enD, 255);
  }
  else if(val == 'S')
  {
   Serial.println("stop");
      digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA,0 );
   digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB,0 );
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC,0 );
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD,0 );  
  
  }
   else if(val == 'I')
  {
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA,0 );
   digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB,255 );
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC,255 );
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD,0);
  }
   else if(val == 'G')
  {
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA,255 );
   digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB,0 );
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC,0 );
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD,255);
  }
}
