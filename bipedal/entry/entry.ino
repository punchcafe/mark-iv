/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
#include "lib/servo_handler.cpp"

#include <Servo.h>

Servo myservo;

  // create servo object to control a servo
ServoDriver driver;
ServoCluster cluster;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  driver.setServo(&myservo);
  cluster.setServoDriver(&driver);

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
  driver.setDestination(driver.getDestination() == 90 ? 0 : 90);
  cluster.acctuate();
}
