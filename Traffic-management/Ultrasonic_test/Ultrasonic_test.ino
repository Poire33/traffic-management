// Prototype code for the ultrasonic sensor to detect a vehicle

const int TRIG_PIN = 5;
const int ECHO_PIN = 10;
long duration;
float cms, inches, distance;

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

void setup() {
  // Serial port begin
  Serial.begin(115200);

  // Define inputs and outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
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
  Serial.print(" cm");

  // if statement placeholder for interrupt
  if (cms < distance) {
    Serial.print("Vehicle in range");
    vehicle_green();
    delay(2000);
    ped_red();
    delay(5000);
  }
}
