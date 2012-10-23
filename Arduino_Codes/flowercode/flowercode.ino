#include <Servo.h> 
Servo myservo;
int pos = 0;
int switchState = 0;

int inPin = 2; // the number of the input pin
int outPin = 13; // the number of the output pin

void setup()
{
  pinMode(inPin, INPUT);
  digitalWrite(inPin, HIGH); // turn on the built in pull-up resistor
  pinMode(outPin, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}
void loop()
{  
  switchState = digitalRead(inPin);
  if (switchState == LOW){
    digitalWrite(outPin, HIGH);
    delay(500);
    myservo.write(50);
    delay(1000);
    for(pos = 50; pos < 130; pos += 1)  // goes from 50 degrees to 130 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(30);                       // waits 30ms for the servo to reach the position 
    }
    myservo.write(130);
    delay(3000);
    digitalWrite(outPin, LOW);
  }
  if(switchState == HIGH) {
    myservo.write(50);
  }
}
