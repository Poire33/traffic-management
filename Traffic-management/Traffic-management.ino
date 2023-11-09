#include "scripts.h"

void setup() {

  // Set traffic light pins as outputs
  pinMode(VEHICLE_RED_TOP, OUTPUT);
  pinMode(VEHICLE_AMBER_TOP, OUTPUT);
  pinMode(VEHICLE_GREEN_TOP, OUTPUT);
  pinMode(VEHICLE_RED_BOTTOM, OUTPUT);
  pinMode(VEHICLE_AMBER_BOTTOM, OUTPUT);
  pinMode(VEHICLE_GREEN_BOTTOM, OUTPUT);
}

void loop() {
  vehicle_green();
  delay(6000); // Represents delay while the lights in that specific direction are green
  vehicle_red();
  delay(6000); // Represents delay while the lights in that specific direction are red
}