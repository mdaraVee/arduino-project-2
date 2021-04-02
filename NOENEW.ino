// File: sketch_mobile_robot5_sensors.ino
// Description: Intelligent Mobile Robot - Collision Avoidance
// Environment: Arduino IDE


#include <AFMotor.h>
//AF_DCMotor motor1(1, MOTOR12_64KHZ);
//AF_DCMotor motor2(2, MOTOR12_64KHZ);


// Variables for Trig and Echo of Ultrasonic Sensors
const int echo = A1;
const int trig = A0;
const int echo1 = 7;
const int trig1 = 6;
const int echo2 = A3;
const int trig2 = A2;
const int echo3 = 3;
const int trig3 = 2;
const int echo4 = A5;
const int trig4 = A4;

// Variables for reading data from Ultrasonic Sensors
int distance;
int distance1;
int distance2;
int distance3;
int distance4;
int duration;
String readString;


const int motor1Right = 10;// S1 defines pin 10 as connected to the motor
const int motor2Left = 11; // S2 defines pin 11 as connected to the motor
const int motor1Left = 12;// D1 defines pin 12 as connected to the motor
const int motor2Right = 13;// D2 defines pin 13 as connected to the motor

// Variables for controlling the directions
//const int D1 = 12;
//const int D2 = 13;
// Variables for controlling the speed
//const int S1 = 10;
//const int S2 = 11;

// Variables for speed
int speed;
int forwardSpeed = 0;
int ReverseSpeed = 0;

// Variable for inputs from Serial Port
char Char = 0;

// Setup code to run once
void setup() {
  // Setting the Pins we are going to work with as an OUTPUT and INPUT
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo4, INPUT);
  pinMode(trig4, OUTPUT);

  pinMode(motor1Left, OUTPUT);
  pinMode(motor2Right, OUTPUT);
  pinMode(motor1Right, OUTPUT);
  pinMode(motor2Left, OUTPUT);
  // Setting the data rate
  Serial.begin(9600);
}
// Main code to run repeatedly
void loop() {

  // First Ultrasonic Sensor
  digitalWrite(trig, LOW); // Ultrasonic Sensor doesn't send signal. Giving a LOW pulse beforehand to ensure a clean HIGH pulse.
  delay(20); // Setting delay 0,02 seconds
  digitalWrite(trig, HIGH); // Sending signal
  delayMicroseconds(500); // Setting delay 0,0005 seconds
  digitalWrite(trig, LOW); // Switching off sending signal
  duration = pulseIn(echo, HIGH); // Switching on getting signal
  distance = duration / 58; // Calculating the distance in distance

  // Second Ultrasonic Sensor
  digitalWrite(trig1, LOW); // Ultrasonic Sensor doesn't send signal. Giving a LOW pulse beforehand to ensure a clean HIGH pulse.
  delay(20); // Setting delay 0,02 seconds
  digitalWrite(trig1, HIGH); // Sending signal
  delayMicroseconds(500); // Setting delay 0,0005 seconds
  digitalWrite(trig1, LOW); // Switching off sending signal
  duration = pulseIn(echo1, HIGH); // Switching on getting signal
  distance1 = duration / 58; // Calculating the distance in distance

  // Third Ultrasonic Sensor
  digitalWrite(trig2, LOW); // Ultrasonic Sensor doesn't send signal. Giving a LOW pulse beforehand to ensure a clean HIGH pulse.
  delay(20); // Setting delay 0,02 seconds
  digitalWrite(trig2, HIGH); // Sending signal
  delayMicroseconds(500); // Setting delay 0,0005 seconds
  digitalWrite(trig2, LOW); // Switching off sending signal
  duration = pulseIn(echo2, HIGH); // Switching on getting signal
  distance2 = duration / 58; // Calculating the distance in distance

  // Fourth Ultrasonic Sensor
  digitalWrite(trig3, LOW); // Ultrasonic Sensor doesn't send signal. Giving a LOW pulse beforehand to ensure a clean HIGH pulse.
  delay(20); // Setting delay 0,02 seconds
  digitalWrite(trig3, HIGH); // Sending signal
  delayMicroseconds(500); // Setting delay 0,0005 seconds
  digitalWrite(trig3, LOW); // Switching off sending signal
  duration = pulseIn(echo3, HIGH); // Switching on getting signal
  distance3 = duration / 58; // Calculating the distance in distance

  // Fifth Ultrasonic Sensor
  digitalWrite(trig4, LOW); // Ultrasonic Sensor doesn't send signal. Giving a LOW pulse beforehand to ensure a clean HIGH pulse.
  delay(20); // Setting delay 0,02 seconds
  digitalWrite(trig4, HIGH); // Sending signal
  delayMicroseconds(500); // Setting delay 0,0005 seconds
  digitalWrite(trig4, LOW); // Switching off sending signal
  duration = pulseIn(echo4, HIGH); // Switching on getting signal
  distance4 = duration / 58; // Calculating the distance in distance

  // Checking the distance for Alarm and make the mobile robot stop if the distance is critical
  if (distance > 0 && distance < 30) {
    if (forwardSpeed > 0) {
      digitalWrite(motor2Left, LOW);
      digitalWrite(motor2Right, HIGH);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    if (ReverseSpeed > 0) {
      digitalWrite(motor2Left, HIGH);
      digitalWrite(motor2Right, LOW);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    forwardSpeed = 0; ReverseSpeed = 0;
  }
  if (distance1 > 0 && distance1 < 30) {
    if (forwardSpeed > 0) {
      digitalWrite(motor2Left, LOW);
      digitalWrite(motor2Right, HIGH);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    if (ReverseSpeed > 0) {
      digitalWrite(motor2Left, HIGH);
      digitalWrite(motor2Right, LOW);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    forwardSpeed = 0; ReverseSpeed = 0;
  }
  if (distance2 > 0 && distance2 < 30) {
    if (forwardSpeed > 0) {
      digitalWrite(motor2Left, LOW);
      digitalWrite(motor2Right, HIGH);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    if (ReverseSpeed > 0) {
      digitalWrite(motor2Left, HIGH);
      digitalWrite(motor2Right, LOW);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    forwardSpeed = 0; ReverseSpeed = 0;
  }
  if (distance3 > 0 && distance3 < 30) {
    if (forwardSpeed > 0) {
      digitalWrite(motor2Left, LOW);
      digitalWrite(motor2Right, HIGH);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    if (ReverseSpeed > 0) {
      digitalWrite(motor2Left, HIGH);
      digitalWrite(motor2Right, LOW);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    forwardSpeed = 0; ReverseSpeed = 0;
  }
  if (distance4 > 0 && distance4 < 30) {
    if (forwardSpeed > 0) {
      digitalWrite(motor2Left, LOW);
      digitalWrite(motor2Right, HIGH);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    if (ReverseSpeed > 0) {
      digitalWrite(motor2Left, HIGH);
      digitalWrite(motor2Right, LOW);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
      delay(200);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }
    forwardSpeed = 0; ReverseSpeed = 0;
  }

  // Reading the input
  Char = Serial.read();

  // Checking the input and implementing the command - FORWARD
  if (Char == '1') {

    // Checking if Mobile Robot is moving back
    if (ReverseSpeed > 0) {
      ReverseSpeed = 0;
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }

    // Setting the direction to forward
    digitalWrite(motor2Left, HIGH);
    digitalWrite(motor2Right, LOW);

    // Setting the speed
    if (forwardSpeed <= 80) {
      forwardSpeed = 80;
    }
    if (forwardSpeed <= 185) {
      forwardSpeed = forwardSpeed + 15;
    }
    if (forwardSpeed > 200) {
      forwardSpeed = 250;
    }
    analogWrite(motor1Left, FORWARD);
    analogWrite(motor1Right, FORWARD);
  }

  // Checking the input and implementing the command - BACK
  if (Char == '2') {

    // Checking if Mobile Robot is moving forward
    if (forwardSpeed > 0) {
      forwardSpeed = 0;
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }

    // Setting the direction to back
    digitalWrite(motor2Left, LOW);
    digitalWrite(motor2Right, HIGH);

    // Setting the speed
    if (ReverseSpeed <= 80) {
      ReverseSpeed = 80;
    }
    if (ReverseSpeed <= 185) {
      ReverseSpeed = ReverseSpeed + 15;
    }
    if (ReverseSpeed > 200) {
      ReverseSpeed = 250;
    }
    analogWrite(motor1Left, BACKWARD);
    analogWrite(motor1Right, BACKWARD);
  }

  // Checking the input and implementing the command - STOP
  if (Char == '0') {
    forwardSpeed = 0;
    ReverseSpeed = 0;
    analogWrite(motor1Left, 0);
    analogWrite(motor1Right, 0);
  }

  // Checking the input and implementing the command - LEFT
  if (Char == '3') {

    // Setting the direction to left-forward while standing still
    if (forwardSpeed == 0 && ReverseSpeed == 0) {
      digitalWrite(motor2Left, HIGH);
      digitalWrite(motor2Right, HIGH);

      // Setting the speed
      analogWrite(motor1Left, 250);
      analogWrite(motor1Right, 250);
      delay(400);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }

    // Setting the direction to left-forward while moving
    if (forwardSpeed > 0 && ReverseSpeed == 0) {
      analogWrite(motor1Left, FORWARD + 50);
      analogWrite(motor1Right, 0);
      delay(300);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
    }

    // Setting the direction to left-back while moving
    if (ReverseSpeed > 0 && forwardSpeed == 0) {
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, BACKWARD + 50);
      delay(300);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
    }
  }

  // Checking the input and implementing the command - RIGHT
  if (Char == '4') {

    // Setting the direction to right-forward while standing still
    if (forwardSpeed == 0 && ReverseSpeed == 0) {
      digitalWrite(motor2Left, LOW);
      digitalWrite(motor2Right, LOW);

      // Setting the speed
      analogWrite(motor1Left, 250);
      analogWrite(motor1Right, 250);
      delay(400);
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, 0);
    }

    // Setting the direction to right-forward while moving
    if (forwardSpeed > 0 && ReverseSpeed == 0) {
      analogWrite(motor1Left, 0);
      analogWrite(motor1Right, FORWARD + 50);
      delay(300);
      analogWrite(motor1Left, FORWARD);
      analogWrite(motor1Right, FORWARD);
    }

    // Setting the direction to right-back while moving
    if (ReverseSpeed > 0 && forwardSpeed == 0) {
      analogWrite(motor1Left, BACKWARD + 50);
      analogWrite(motor1Right, 0);
      delay(300);
      analogWrite(motor1Left, BACKWARD);
      analogWrite(motor1Right, BACKWARD);
    }
  }

  // Sending the string with data from Ultrasonic Sensors to Serial Port
  Serial.print(distance);
  Serial.print("_");
  Serial.print(distance1);
  Serial.print("_");
  Serial.print(distance2);
  Serial.print("_");
  Serial.print(distance3);
  Serial.print("_");
  Serial.println(distance4);

}
