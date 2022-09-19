#include<AFMotor.h>

#define in1 A0
#define in2 A2

AF_DCMotor motor1(2);
AF_DCMotor motor2(3);

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a,b;
  a=b=0;
  a = digitalRead(in1);
  b = digitalRead(in2);
  if(a == 0 && b == 1) {
    right();
  }
  else if(a == 1 && b == 0) {
    left();
  }
  else if(a == 0 && b == 0) forward();
  else stay();
}

void forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void right(){
  motor1.run(RELEASE);
  motor1.run(BACKWARD);
}

void left(){
  motor1.run(FORWARD);
  motor2.run(RELEASE);
}

void stay(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
