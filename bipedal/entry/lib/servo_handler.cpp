#include "servo_driver.cpp";

class ServoCluster{
  int delaySec = 15;
  // Make a list
public:
  ServoDriver* servoDriver;

  ServoCluster(){}
  void setServoDriver(ServoDriver* driver){
    this->servoDriver = driver;
  }
  void acctuate(){
    while(!servoDriver->isComplete()){
      servoDriver->update();
      delay(delaySec);
    }
  }
};
