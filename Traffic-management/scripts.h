// This is the header file for all repeatable and pre-defined patters in the traffic management system.

// Set pins for traffic lights
#define VEHICLE_RED_TOP 32
#define VEHICLE_AMBER_TOP 33
#define VEHICLE_GREEN_TOP 25
#define VEHICLE_RED_BOTTOM 26
#define VEHICLE_AMBER_BOTTOM 14
#define VEHICLE_GREEN_BOTTOM 13

void vehicle_red() {
  // Turn vehicle traffic lights red

  digitalWrite(VEHICLE_GREEN_TOP, LOW);
  digitalWrite(VEHICLE_GREEN_BOTTOM, LOW);
  digitalWrite(VEHICLE_AMBER_TOP, HIGH);
  digitalWrite(VEHICLE_AMBER_BOTTOM, HIGH);
  delay(2000);
  digitalWrite(VEHICLE_AMBER_TOP, LOW);
  digitalWrite(VEHICLE_AMBER_BOTTOM, LOW);
  digitalWrite(VEHICLE_RED_TOP, HIGH);
  digitalWrite(VEHICLE_RED_BOTTOM, HIGH);
}

void vehicle_green() {
  digitalWrite(VEHICLE_RED_TOP, LOW);
  digitalWrite(VEHICLE_RED_BOTTOM, LOW);
  digitalWrite(VEHICLE_GREEN_TOP, HIGH);
  digitalWrite(VEHICLE_GREEN_BOTTOM, HIGH);
}