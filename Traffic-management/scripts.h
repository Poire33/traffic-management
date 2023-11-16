// This is the header file for all repeatable and pre-defined patterns in the traffic management system.

// Set pins for traffic lights
#define VEHICLE_RED_TOP 32
#define VEHICLE_AMBER_TOP 33
#define VEHICLE_GREEN_TOP 25
#define VEHICLE_RED_BOTTOM 26
#define VEHICLE_AMBER_BOTTOM 14
#define VEHICLE_GREEN_BOTTOM 13

// Set pins for pedestrian beg buttons and lights
#define PED_RED_RIGHT 0
#define PED_GREEN_RIGHT 2
#define BUTTON_RIGHT 15
#define BUTTON_LED_RIGHT 4
#define PED_RED_LEFT 23
#define PED_GREEN_LEFT 22
#define BUTTON_LEFT 21
#define BUTTON_LED_LEFT 19


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

void ped_red() {
  digitalWrite(PED_GREEN_RIGHT, LOW);
  digitalWrite(PED_GREEN_LEFT, LOW);
  digitalWrite(PED_RED_RIGHT, HIGH);
  digitalWrite(PED_RED_LEFT, HIGH);
}

void ped_green() {
  digitalWrite(PED_RED_RIGHT, LOW);
  digitalWrite(PED_RED_LEFT, LOW);
  digitalWrite(PED_GREEN_RIGHT, HIGH);
  digitalWrite(PED_GREEN_LEFT, HIGH);
}

void beg_button() {
  if(digitalRead(BUTTON_RIGHT) == HIGH || digitalRead(BUTTON_LEFT) == HIGH) {
    digitalWrite(BUTTON_LED_RIGHT, HIGH);
    digitalWrite(BUTTON_LED_LEFT, HIGH);
    // Insert possible delay here when using HC-SR04 to detect cyclists and motor vehicles; in any case, limit delay to about 10s
    vehicle_red();
    delay(2000);
    digitalWrite(BUTTON_LED_RIGHT, LOW);
    digitalWrite(BUTTON_LED_LEFT, LOW);
    ped_green();
    delay(17000);
    ped_red();
    delay(2000);
    vehicle_green();
  }
}

void check_vehicles() {
  vehicle_green();
  ped_red();
  delay(10000);
  beg_button();
}