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

// Set pins for sensors, see slide 20+ for code
#define TRIG 12
#define ECHO 35

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
  Serial.println("Beg button function");
  digitalWrite(BUTTON_LED_RIGHT, HIGH);
  digitalWrite(BUTTON_LED_LEFT, HIGH);
  // Insert delay here when using HC-SR04 to detect cyclists and motor vehicles; in any case, limit delay to about 10s
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

// Respond to presses of the beg button; have right and left hand sides different if applicable (mainly if there is a refuge island). No delays allowed in interrupts, except delayMicroseconds()
void right_beg() {
  // Test code using RHS beg button, otherwise use beg_button();
  digitalWrite(VEHICLE_GREEN_TOP, HIGH);
  digitalWrite(VEHICLE_GREEN_BOTTOM, HIGH);
  digitalWrite(VEHICLE_AMBER_TOP, HIGH);
  digitalWrite(VEHICLE_AMBER_BOTTOM, HIGH);
  digitalWrite(VEHICLE_RED_TOP, HIGH);
  digitalWrite(VEHICLE_RED_BOTTOM, HIGH);
  digitalWrite(PED_RED_RIGHT, HIGH);
  digitalWrite(PED_RED_LEFT, HIGH);
  digitalWrite(PED_GREEN_RIGHT, HIGH);
  digitalWrite(PED_GREEN_LEFT, HIGH);
  digitalWrite(BUTTON_LED_RIGHT, HIGH);
  digitalWrite(BUTTON_LED_LEFT, HIGH);
}

void left_beg() {
  beg_button();
}

void check_vehicles() {
  vehicle_green();
  ped_red();
  delay(10000); // Use interrupts to break out of the delay
  beg_button(); // Used exclusively to turn the pedestrian side to green for now (comment out line to use beg buttons "properly")
}