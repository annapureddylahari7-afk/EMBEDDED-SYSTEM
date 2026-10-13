#include<SoftwareSerial.h>
int m11=2;
int m12=3;
int m21=4;
int m22=5;

void setup() {
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}

void loop() {
  forward();
  delay(2000);
  backward();
  delay(2000);
  left();
  delay(1000);
  right();
  delay(1000);
  stopCar();
  delay(2000);
}

void forward() {
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
}

void backward() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
}

void left() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
}

void right() {
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
}

void stopCar() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
}
