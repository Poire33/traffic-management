// This is the header file for all repeatable and pre-defined patters in the traffic management system.

// Set pins for traffic lights
#define VEHICLE_RED_TOP 32
#define VEHICLE_AMBER_TOP 33
#define VEHICLE_GREEN_TOP 25
#define VEHICLE_RED_BOTTOM 26
#define VEHICLE_AMBER_BOTTOM 14
#define VEHICLE_GREEN_BOTTOM 13

// Set pins for pedestrian beg buttons and lights
// Change below pin numbers when design decided, sample pin numbers for now
#define PED_RED_RIGHT 1
#define PED_GREEN_RIGHT 2
#define BUTTON_RIGHT 3
#define BUTTON_LED_RIGHT 4
#define PED_RED_LEFT 5
#define PED_GREEN_LEFT 6
#define BUTTON_LEFT 7
#define BUTTON_LED_LEFT 8


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
  if(digitalRead(BUTTON_RIGHT) == LOW || digitalRead(BUTTON_LEFT) == LOW) {
    digitalWrite(BUTTON_LED_RIGHT, HIGH);
    digitalWrite(BUTTON_LED_LEFT, HIGH);
    vehicle_red();
    delay(2000);
    ped_green();
    digitalWrite(BUTTON_LED_RIGHT, LOW);
    digitalWrite(BUTTON_LED_LEFT, LOW);
    delay(17000);
    ped_red();
    delay(2000);
    vehicle_green();
  }
}

void check_vehicles() {
  beg_button();
  
}