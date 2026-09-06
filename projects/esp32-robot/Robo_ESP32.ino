/*
 * =========================================================================
 * Project: ESP32 Smart Rover Controller
 * Description: Bluetooth Serial & PWM Motor Control for Robotics Club
 * Hardware: ESP32 NodeMCU + L298N / TB6612FNG Motor Driver
 * =========================================================================
 */

#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// Pin Definitions
const int MOTOR_LEFT_F = 18;  // IN1
const int MOTOR_LEFT_B = 19;  // IN2
const int MOTOR_RIGHT_F = 22; // IN3
const int MOTOR_RIGHT_B = 23; // IN4
const int LED_PIN = 2;        // On-board LED

// PWM Configuration (ESP32 LEDC)
const int PWM_FREQ = 1000;
const int PWM_RES = 8;        // 8-bit resolution (0-255)
const int MOTOR_SPEED = 200;  // Default drive speed (0 - 255)

void setup() {
  Serial.begin(115200);

  // Initialize Motor Pins as Outputs
  pinMode(MOTOR_LEFT_F, OUTPUT);
  pinMode(MOTOR_LEFT_B, OUTPUT);
  pinMode(MOTOR_RIGHT_F, OUTPUT);
  pinMode(MOTOR_RIGHT_B, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  stopMotors();

  // Initialize Bluetooth with Device Name
  SerialBT.begin("Robo_ESP32_Rover");
  Serial.println("Bluetooth started! Pair with 'Robo_ESP32_Rover'");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(command);

    switch (command) {
      case 'F':
      case 'f':
        moveForward();
        break;
      case 'B':
      case 'b':
        moveBackward();
        break;
      case 'L':
      case 'l':
        turnLeft();
        break;
      case 'R':
      case 'r':
        turnRight();
        break;
      case 'S':
      case 's':
      default:
        stopMotors();
        break;
    }
  }
  delay(20);
}

void moveForward() {
  digitalWrite(MOTOR_LEFT_F, HIGH);
  digitalWrite(MOTOR_LEFT_B, LOW);
  digitalWrite(MOTOR_RIGHT_F, HIGH);
  digitalWrite(MOTOR_RIGHT_B, LOW);
  digitalWrite(LED_PIN, HIGH);
}

void moveBackward() {
  digitalWrite(MOTOR_LEFT_F, LOW);
  digitalWrite(MOTOR_LEFT_B, HIGH);
  digitalWrite(MOTOR_RIGHT_F, LOW);
  digitalWrite(MOTOR_RIGHT_B, HIGH);
  digitalWrite(LED_PIN, HIGH);
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT_F, LOW);
  digitalWrite(MOTOR_LEFT_B, HIGH);
  digitalWrite(MOTOR_RIGHT_F, HIGH);
  digitalWrite(MOTOR_RIGHT_B, LOW);
  digitalWrite(LED_PIN, HIGH);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT_F, HIGH);
  digitalWrite(MOTOR_LEFT_B, LOW);
  digitalWrite(MOTOR_RIGHT_F, LOW);
  digitalWrite(MOTOR_RIGHT_B, HIGH);
  digitalWrite(LED_PIN, HIGH);
}

void stopMotors() {
  digitalWrite(MOTOR_LEFT_F, LOW);
  digitalWrite(MOTOR_LEFT_B, LOW);
  digitalWrite(MOTOR_RIGHT_F, LOW);
  digitalWrite(MOTOR_RIGHT_B, LOW);
  digitalWrite(LED_PIN, LOW);
}
