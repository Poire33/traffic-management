// Prototype code for the ultrasonic sensor to detect a vehicle

#include "scripts.h"

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;
long duration;
float cms, inches, distance;

void setup() {
  // Serial port begin
  Serial.begin(115200);

  // Define inputs and outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  ped_green();
  // vehicle_red();

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  cms = (duration / 2) / 29.1;
  distance = 5; // Reconfigure distance variable if required
  Serial.print("Nearest vehicle at ");
  Serial.print(cms);
  Serial.print(" cm\n");
  delay(500);

  // if statement placeholder for interrupt
  if (cms < distance) {
    Serial.print("Vehicle in range\n");
    vehicle_green();
    delay(2000);
    ped_red();
    delay(5000);
  }
}
