/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;

class ServoDriver {
  // Add map of movements, so that each update is determined by where it's supposed to be going?
  // Introduce update class
  // Updateable Interface, what to do in the window. Have overarching 'updatate frame'
  public:
  Servo* servo;
  int currentPos = 0;
  // Delay for motor to move one degree
  int degreeDelay = 15;
  
  ServoDriver(Servo* motor){
    this->servo = motor;
  }

  ServoDriver(){}

  void setServo(Servo* servo){
    this->servo = servo;
    }
  
  void moveTo(int dest){
    if(dest == currentPos) return;
    if(dest > currentPos){
      int startPoint = currentPos*1;
      for(int i = startPoint*1; i < dest; i += 1){
        servo->write(i);
        this->currentPos = i;
        delay(degreeDelay);
      }
    } else {
      int startPoint = currentPos*1;
      for(int i = startPoint*1; i > dest; i-= 1){
        servo->write(i);
        this->currentPos = i;
        delay(degreeDelay);
      }
    }
  }
  
};

  // create servo object to control a servo
ServoDriver driver;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  driver.setServo(&myservo);
  //So and takes the referrence of the object
}

void sweep(){
    myservo.write(pos);  
  for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(75);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(75);                       // waits 15ms for the servo to reach the position
  }
}

void loop() {
  driver.moveTo(0);
  delay(1000);
  driver.moveTo(180);
  delay(1000);
}
