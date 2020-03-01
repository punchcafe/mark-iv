#include "servo_driver.cpp";

class ServoCluster{
  int delaySec = 15;

  // TODO: encapsulate, make a List of Servo Referrences
public:
  ServoDriver* servoDrivers;
  // ClassRefferences can point to arrays, so when you don't know the
  // size of an array, make it a refference

  ServoCluster(){
  }
  boolean setServoCluster(ServoDriver* cluster){
    this->servoDrivers = cluster;
    return true;
  }
  void acctuate(){
    while(!acctuationFinished()){
      for(int i = 0; i < sizeof(servoDrivers); i++){
        servoDrivers[i].update();
      }
      delay(delaySec);
    }
  }

  boolean acctuationFinished(){
    for(int i = 0; i < sizeof(servoDrivers); i++){
      if(!servoDrivers[i].isComplete()){
        return false;
      }
    }
    return true;
  }
};
