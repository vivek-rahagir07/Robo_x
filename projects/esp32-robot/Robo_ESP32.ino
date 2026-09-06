/*
 * =========================================================================
 * Project: ESP32 Smart Rover Controller
 * Description: Bluetooth Serial & PWM Motor Control for Robotics Club
 * Hardware: ESP32 NodeMCU + L298N / TB6612FNG Motor Driver
 * =========================================================================
 */

#include "BluetoothSerial.h"

// Check if Bluetooth is properly enabled in your ESP32 board settings
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

// --- L298N Pin Definitions ---
// Left Motors
const int ENA = 14; // Left Speed (PWM)
const int IN1 = 26; // Left Forward
const int IN2 = 27; // Left Reverse

// Right Motors
const int ENB = 15; // Right Speed (PWM)
const int IN3 = 32; // Right Forward
const int IN4 = 33; // Right Reverse

int motorSpeed = 255; // Default max speed (0-255)

void setup() {
  Serial.begin(115200);

  // Configure pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ensure motors are stopped on boot
  stopMotors();

  // Initialize Bluetooth
  SerialBT.begin("Robo_X"); 
  Serial.println("Bluetooth Started! Ready to pair...");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    
    // Execute movement based on the received character
    switch (command) {
      case 'F': moveForward(motorSpeed); break;
      case 'B': moveBackward(motorSpeed); break;
      case 'L': turnLeft(motorSpeed); break;
      case 'R': turnRight(motorSpeed); break;
      case 'S': stopMotors(); break;
      
      // Map numbers 0-9 from the app to PWM speeds (0 to 255)
      case '0': motorSpeed = 0; break;
      case '1': motorSpeed = 28; break;
      case '2': motorSpeed = 56; break;
      case '3': motorSpeed = 85; break;
      case '4': motorSpeed = 113; break;
      case '5': motorSpeed = 141; break;
      case '6': motorSpeed = 170; break;
      case '7': motorSpeed = 198; break;
      case '8': motorSpeed = 226; break;
      case '9': motorSpeed = 255; break;
    }
  }
}

// ==========================================
//           MOVEMENT FUNCTIONS
// ==========================================

void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void moveBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft(int speed) {
  // Left side reverse, Right side forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnRight(int speed) {
  // Left side forward, Right side reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}