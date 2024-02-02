// Prototype code for the ultrasonic sensor to detect a vehicle

const int TRIG_PIN = 5;
const int ECHO_PIN = 10;
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
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  cms = (duration / 2) / 29.1;
  distance = 5; // Reconfigure distance variable to edit the 
  Serial.print("Nearest vehicle at ");
  Serial.print(cms);
  Serial.print(" cm");

  // if statement placeholder for interrupt
  if (cms < distance) {
    vehicle_green();
    ped_red();
  }
}
