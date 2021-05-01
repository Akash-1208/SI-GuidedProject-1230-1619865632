#include<Servo.h>
Servo myservo;
int trigpin=3;
int echopin=7;
void setup()
{
   pinMode(10,OUTPUT);
   pinMode(trigpin,OUTPUT);
   pinMode(echopin,INPUT);
   Serial.begin(9600);
   myservo.attach(8);
}
  
  
  

void loop()
{
  digitalWrite(trigpin,HIGH);
  delay(1000);
  digitalWrite(trigpin,LOW);
  int duration=pulseIn(echopin,HIGH);
  int distance=(duration*0.034)/2;
  Serial.println("the distance is");
  Serial.println(distance);
  
  
  if(distance<=50)
  {
    digitalWrite(10,HIGH);

    myservo.write(180);
    Serial.println("the angle it is rotated is 180");
    Serial.println("the car has addrived to less than 50 meters");

 
   

  }
  else
  {
    digitalWrite(10,LOW);

     myservo.write(0);
     Serial.println("the angle it is rotated is 0");
    delay(1000);
    Serial.println("the car has moved more than 50 meters");
    
    }
}
