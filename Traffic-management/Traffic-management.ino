void setup() {
  // Set pins for traffic lights
  #define VEHICLE_RED_TOP 32
  #define VEHICLE_AMBER_TOP 33
  #define VEHICLE_GREEN_TOP 25
  #define VEHICLE_RED_BOTTOM 26
  #define VEHICLE_AMBER_BOTTOM 14
  #define VEHICLE_GREEN_BOTTOM 13

  // Set traffic light pins as outputs
  pinMode(VEHICLE_RED_TOP, OUTPUT);
  pinMode(VEHICLE_AMBER_TOP, OUTPUT);
  pinMode(VEHICLE_GREEN_TOP, OUTPUT);
  pinMode(VEHICLE_RED_BOTTOM, OUTPUT);
  pinMode(VEHICLE_AMBER_BOTTOM, OUTPUT);
  pinMode(VEHICLE_GREEN_BOTTOM, OUTPUT);
}

void loop() {
  digitalWrite(VEHICLE_RED_TOP, LOW);
  digitalWrite(VEHICLE_RED_BOTTOM, LOW);
  digitalWrite(VEHICLE_GREEN_TOP, HIGH);
  digitalWrite(VEHICLE_GREEN_BOTTOM, HIGH);
  delay(6000); // Represents delay while the lights in that specific direction are green
  digitalWrite(VEHICLE_GREEN_TOP, LOW);
  digitalWrite(VEHICLE_GREEN_BOTTOM, LOW);
  digitalWrite(VEHICLE_AMBER_TOP, HIGH);
  digitalWrite(VEHICLE_AMBER_BOTTOM, HIGH);
  delay(2000);
  digitalWrite(VEHICLE_AMBER_TOP, LOW);
  digitalWrite(VEHICLE_AMBER_BOTTOM, LOW);
  digitalWrite(VEHICLE_RED_TOP, HIGH);
  digitalWrite(VEHICLE_RED_BOTTOM, HIGH);
  delay(6000); // Represents delay while the lights in that specific direction are red
}