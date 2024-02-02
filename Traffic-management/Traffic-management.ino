#include "scripts.h"

void setup() {

  // Set traffic light pins as outputs
  pinMode(VEHICLE_RED_TOP, OUTPUT);
  pinMode(VEHICLE_AMBER_TOP, OUTPUT);
  pinMode(VEHICLE_GREEN_TOP, OUTPUT);
  pinMode(VEHICLE_RED_BOTTOM, OUTPUT);
  pinMode(VEHICLE_AMBER_BOTTOM, OUTPUT);
  pinMode(VEHICLE_GREEN_BOTTOM, OUTPUT);

  // Set pedestrian light pins as outputs and beg buttons as inputs
  pinMode(PED_RED_RIGHT, OUTPUT);
  pinMode(PED_GREEN_RIGHT, OUTPUT);
  pinMode(BUTTON_LED_RIGHT, OUTPUT);
  pinMode(BUTTON_RIGHT, INPUT);
  pinMode(PED_RED_LEFT, OUTPUT);
  pinMode(PED_GREEN_LEFT, OUTPUT);
  pinMode(BUTTON_LED_LEFT, OUTPUT);
  pinMode(BUTTON_LEFT, INPUT);

  // Set ultrasonic sensor as 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Configure interrupts for pedestrian beg buttons
  // attachInterrupt(BUTTON_RIGHT, right_beg, HIGH);
  // attachInterrupt(BUTTON_LEFT, left_beg, HIGH); -- An empty attachInterrupt doesn't cause any problems but once beg_button(); or other code is added, the board constantly reboots. When the function is set to LOW, nothing happens when the button is pressed. No rebooting.
}

void loop() {
  check_vehicles();
  /*
  Old code

  delay(6000); // Represents delay while the lights in that specific direction are green
  vehicle_red();
  ped_green();
  delay(6000); // Represents delay while the lights in that specific direction are red
  */
}