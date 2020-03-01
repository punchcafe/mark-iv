#include <Servo.h>

class ServoDriver {
  private:
    Servo* servo;
    int currentPosition;
    int destination;

  public:
    ServoDriver(){}
    ServoDriver(int random){}
    void update(){
      if(currentPosition == destination){
        return;
      }
      int movement = currentPosition > destination ? -1 : 1;
      servo->write(currentPosition + movement);
      this->currentPosition = currentPosition + movement;
    }
    boolean isComplete(){
      return currentPosition == destination;
    }
    void setServo(Servo* servo){
      this->servo = servo;
    }
    void setDestination(int dest){
      this->destination = dest;
    }

    int getDestination(){
      return destination;
    }

};
