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
Servo myservo2;

  // create servo object to control a servo
ServoDriver driver1;
ServoDriver driver2;
ServoCluster cluster;
ServoDriver* clusterArray;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  //driver.setServo(&myservo);
  clusterArray = new ServoDriver[2]{0};
  clusterArray[0].setServo(&myservo);
  clusterArray[0].setDestination(90);
  clusterArray[1].setServo(&myservo2);
  clusterArray[1].setDestination(90);
  cluster.setServoCluster(clusterArray);

  //So and takes the referrence of the object
}

void loop() {
  for(int i=0; i < 2; i++){
    clusterArray[i].setDestination(clusterArray[i].getDestination() == 45 ? 0 : 45);
  }
  cluster.acctuate();
}
