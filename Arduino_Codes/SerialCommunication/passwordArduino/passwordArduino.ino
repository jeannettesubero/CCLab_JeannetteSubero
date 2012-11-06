#include <Servo.h> 
Servo myservo;
int closed = 0;
int opened = 150;
int redLED = 11;
int greenLED = 10;
int servo = 9;

int incomingByte;      // a variable to read incoming serial data into

void setup()
{
  //pinMode(inPin, INPUT);
  //digitalWrite(inPin, HIGH); // turn on the built in pull-up resistor
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  myservo.attach(servo);

  Serial.begin(9600);

  incomingByte == 'L';
  myservo.write(closed);
}


void loop()
{
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(greenLED, HIGH);
      myservo.write(opened);
      delay(20000);
    }

    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      myservo.write(closed);
    }

    if (incomingByte == 'X') {
      digitalWrite(redLED, HIGH);
      delay(1000);
    }
  }
}
