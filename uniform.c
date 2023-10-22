#include <Servo.h>

Servo servo;
const int trigPin = 9;  // Trigger pin for the ultrasonic sensor
const int echoPin = 10; // Echo pin for the ultrasonic sensor

void setup() {
  servo.attach(8); // Attach the servo to pin 8
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distanceInCentimeters = duration / 29 / 2;
  return distanceInCentimeters;
}

void loop() {
  int angle;
  for (angle = 0; angle <= 180; angle += 15) {
    servo.write(angle);
    delay(500);
    int distance = measureDistance();
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" degrees, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  servo.write(90); // Return the servo to the starting position
  delay(500);
}
