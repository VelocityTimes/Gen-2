#include <Servo.h>

const int STOP = 90;
const int SPEED = 5;

const int TOP_MOTOR = 9;
const int BOTTOM_MOTOR = 10;
const int LEFT_MOTOR = 6;
const int RIGHT_MOTOR = 11;

Servo top;
Servo bottom;
Servo left;
Servo right;

int state = 0;
int flag = 0;

int exercise = 5;

void spinTop(int speed) {

  if (speed == 0) {
    top.detach();
  } else {
    top.attach(TOP_MOTOR);
  }
  
  top.write(STOP + speed);
}

void spinBottom(int speed) {

  if (speed == 0) {
    bottom.detach();
  } else {
    bottom.attach(BOTTOM_MOTOR);
  }
  
  bottom.write(STOP + speed);
}

void spinLeft(int speed) {

  if (speed == 0) {
    left.detach();
  } else {
    left.attach(LEFT_MOTOR);
  }
  
  left.write(STOP + speed);
}

void spinRight(int speed) {

  if (speed == 0) {
    right.detach();
  } else {
    right.attach(RIGHT_MOTOR);
  }
  
  right.write(STOP + speed);
}

void setup() {

  spinTop(0);
  spinBottom(0);
  spinLeft(0);
  spinRight(0);
  
  Serial.begin(57600);
  
}

void loop() {
  
  if(Serial.available() > 0){
    state = Serial.read();
    Serial.write(state);
    Serial.println(); 
    flag = 0;
  }

  // VERTICAL EXTENSIONS
  if (state == '0' && flag == 0) {

    spinTop(0);
    spinBottom(0);
    spinLeft(0);
    spinRight(0);

    spinTop(SPEED);
    delay(11300);
    spinTop(-SPEED);
    delay(13300);

    spinTop(0);

    spinBottom(SPEED);
    delay(8000);
    spinBottom(-SPEED);
    delay(9200);

    spinBottom(0);
  }
  
  // HORIZONTAL DEVIATIONS
  else if (state == '1' && flag == 0) {
    
    spinTop(0);
    spinBottom(0);
    spinLeft(0);
    spinRight(0);

    spinLeft(SPEED);
    delay(8000);
    spinLeft(-SPEED);
    delay(10000);

    spinLeft(0);

    spinRight(SPEED);
    delay(8000);
    spinRight(-SPEED);
    delay(10000);

    spinRight(0);

  }

  // CROSS MOTION
  else if (state == '2' && flag == 0) {

    spinTop(0);
    spinBottom(0);
    spinLeft(0);
    spinRight(0);

    spinTop(SPEED);
    delay(11300);
    spinTop(-SPEED);
    delay(13300);

    spinTop(0);

    spinBottom(SPEED);
    delay(8000);
    spinBottom(-SPEED);
    delay(9200);

    spinBottom(0);

    spinLeft(SPEED);
    delay(8000);
    spinLeft(-SPEED);
    delay(10000);

    spinLeft(0);

    spinRight(SPEED);
    delay(8000);
    spinRight(-SPEED);
    delay(10000);

    spinRight(0);
    
  }

  // STOP
  else if (state == '5') {
    spinTop(0);
    spinBottom(0);
    spinLeft(0);
    spinRight(0);
  }
  
}


