#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
    motor1.setSpeed(200);
    motor1.run(RELEASE);

    motor2.setSpeed(200);
    motor2.run(RELEASE);

    motor3.setSpeed(200);
    motor3.run(RELEASE);

    motor4.setSpeed(200);
    motor4.run(RELEASE);

}

void loop() {

    goForward();
    delay(1000);
    turnLeft();
    delay(500);
    goForward();
    delay(1000);
    goBackward();
    delay(1000);
    turnRight();
    delay(300);
    goForward();
    delay(1000);

    stayStill();
    delay(3000);

}

void moveRightWheels(char to){
    switch(to){
        case 'F':
        case 'f':
            motor1.run(FORWARD);
            motor2.run(FORWARD);
            break;
        case 'B':
        case 'b':
            motor1.run(BACKWARD);
            motor2.run(BACKWARD);
            break;
    }
}

void moveLeftWheels(char to){
    switch(to){
        case 'F':
        case 'f':
            motor3.run(FORWARD);
            motor4.run(FORWARD);
            break;
        case 'B':
        case 'b':
            motor3.run(BACKWARD);
            motor4.run(BACKWARD);
            break;
    }
}

void stayStill(){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    delay(300);
}

void goForward(){
    stayStill();
    moveRightWheels('F');
    moveLeftWheels('F');
}

void goBackward(){
    stayStill();
    moveRightWheels('B');
    moveLeftWheels('B');
}

void turnLeft(){
    stayStill();
    moveRightWheels('B');
    moveLeftWheels('F');
}

void turnRight(){
    stayStill();
    moveRightWheels('F');
    moveLeftWheels('B');
}
