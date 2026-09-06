# 🤖 ROBOTICS CLUB

<p align="center">
  <img src="logo.png" width="240" alt="Robotics Club Logo">
</p>

<p align="center">
  <b>BUILD • CODE • CREATE • INNOVATE</b>
  <br>
  <i>Official master repository for all club robotics projects, hardware schematics, software firmwares, and engineering resources.</i>
</p>

<p align="center">
  <a href="#-repository-structure"><img src="https://img.shields.io/badge/Architecture-Modular-blue.svg" alt="Architecture"></a>
  <a href="LICENSE"><img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License"></a>
  <a href="CONTRIBUTING.md"><img src="https://img.shields.io/badge/PRs-Welcome-brightgreen.svg" alt="PRs Welcome"></a>
  <img src="https://img.shields.io/badge/Hardware-Open%20Source-orange.svg" alt="Open Hardware">
  <img src="https://img.shields.io/badge/Platform-ESP32%20%7C%20Arduino%20%7C%20RPi-red.svg" alt="Platforms">
</p>

---

## 📑 Table of Contents

- [📂 Repository Structure](#-repository-structure)
- [🚀 Projects](#-projects)
  - [1. Line Follower Robot](#1-line-follower-robot)
  - [2. Obstacle Avoiding Robot](#2-obstacle-avoiding-robot)
  - [3. Multi-DOF Robotic Arm](#3-multi-dof-robotic-arm)
  - [4. Quadcopter Drone](#4-quadcopter-drone)
  - [5. ESP32 Smart Rover](#5-esp32-smart-rover)
- [⚡ Electronics](#-electronics)
  - [Circuits & Prototyping](#circuits--prototyping)
  - [Schematics & EDA Standards](#schematics--eda-standards)
  - [PCB Layout & Manufacturing](#pcb-layout--manufacturing)
  - [Component Selection Guide](#component-selection-guide)
- [💻 Software](#-software)
  - [Arduino Sketches](#arduino)
  - [ESP32 Firmware](#esp32)
  - [Raspberry Pi & ROS](#raspberry-pi)
  - [Python Automation & Kinematics](#python)
  - [Computer Vision & OpenCV](#computer-vision)
- [🛠️ Mechanical](#️-mechanical)
  - [CAD Models](#cad)
  - [3D Printing (STL) Guidelines](#stl)
  - [Hardware Dimensions & Tolerances](#dimensions)
  - [2D Technical Drawings & Laser Cutting](#drawings)
- [📚 Documentation](#-documentation)
  - [Tutorials & Setup Guides](#tutorials--setup-guides)
  - [Hardware & Software Troubleshooting](#troubleshooting-matrix)
- [🧰 Resources](#-resources)
  - [Microcontroller Pinouts](#microcontroller-pinout-reference)
  - [Datasheets & Curated Links](#datasheets--links)
- [🤝 Contributing & Community](#-contributing--community)

---

## 📂 Repository Structure

```text
Robotics-Club/
│
├── README.md                 # Master repository guide & documentation (You are here)
├── CONTRIBUTING.md           # Contribution guidelines, branching & PR standards
├── LICENSE                   # MIT Open-Source License
├── CODE_OF_CONDUCT.md        # Community participation guidelines
│
├── projects/                 # Complete robot builds with BOM, firmware, and wiring
│   ├── line-follower/        # High-speed PID line tracking robot
│   ├── obstacle-avoiding/    # Ultrasonic + Servo autonomous obstacle avoidance rover
│   ├── robotic-arm/          # Multi-axis servo articulated arm with kinematics
│   ├── drone/                # FPV quadcopter with flight controller & BLDC motors
│   └── esp32-robot/          # WiFi / Bluetooth telemetry and app-controlled rover
│
├── electronics/              # Hardware design files and component guides
│   ├── circuits/             # Breadboard layouts, power rails & wiring conventions
│   ├── schematics/           # KiCad & EasyEDA schematic files (.kicad_sch, .pdf)
│   ├── pcb/                  # PCB layout designs (.kicad_pcb) & Gerber production files
│   └── components/           # Component guides, driver ICs, sensors & ratings
│
├── software/                 # Source code, firmware, libraries & algorithms
│   ├── arduino/              # Arduino sketches, timers, and PWM drivers
│   ├── esp32/                # FreeRTOS multitasking, BLE/WiFi stacks & ESP-IDF
│   ├── raspberry-pi/         # Single board computer OS setup, GPIO & ROS 2
│   ├── python/               # Serial communication, autonomy, and robot kinematics
│   └── computer-vision/      # OpenCV tracking, AprilTags, color filtering & camera feeds
│
├── mechanical/               # Mechanical hardware, 3D printing & chassis designs
│   ├── cad/                  # Parametric CAD models (.STEP, Fusion 360, SolidWorks)
│   ├── stl/                  # 3D print ready mesh files (.stl) with slicer recommendations
│   ├── dimensions/           # Mounting hole patterns, chassis footprints & clearance sheets
│   └── drawings/             # 2D engineering drawings, laser-cut DXF/SVG vectors
│
├── documentation/            # Club guides, reports & knowledge base
│   ├── tutorials/            # Step-by-step beginner robotics walkthroughs
│   ├── setup-guides/         # IDE, toolchain & board flasher installations
│   ├── troubleshooting/      # Hardware brownout, motor noise & communication fixes
│   └── project-reports/      # Documentation templates for completed club builds
│
└── resources/                # Quick references, pinouts & datasheets
    ├── datasheets/           # PDF datasheets for ICs, microcontrollers & sensors
    ├── pinouts/              # Pinout graphics for ESP32, Arduino, Raspberry Pi
    ├── tools/                # Essential hardware/software tools recommendations
    └── useful-links/         # Curated simulators (Wokwi), calculators & references
```

---

## 🚀 Projects

Each project folder inside [`projects/`](projects/) is designed as a standalone robot build.

### 1. Line Follower Robot
* **Directory**: [`projects/line-follower/`](projects/line-follower/)
* **Microcontroller**: Arduino Nano / Uno
* **Key Components**: 5-channel TCRT5000 or QTR-8A IR sensor array, TB6612FNG or L298N motor driver, 2x N20 micro gear motors (600 RPM).
* **Control Algorithm**: Proportional-Integral-Derivative (PID) loop calculated from weighted sensor readings:
  $$\text{Error} = \sum (i \times w_i) - \text{Setpoint}$$
  $$\text{Correction} = K_p \cdot \text{Error} + K_d \cdot \frac{d(\text{Error})}{dt} + K_i \cdot \int \text{Error} \, dt$$

---

### 2. Obstacle Avoiding Robot
* **Directory**: [`projects/obstacle-avoiding/`](projects/obstacle-avoiding/)
* **Microcontroller**: Arduino Uno / Nano
* **Key Components**: HC-SR04 ultrasonic distance sensor mounted on an SG90 micro-servo, L298N dual H-bridge driver, 2WD/4WD TT yellow geared motors.
* **Behavior Logic**:
  1. Continuously measures forward clearance ($D$).
  2. If $D < 25\text{ cm}$, robot halts motors.
  3. Servo rotates sensor $180^\circ$ left, records clearance $D_{\text{left}}$.
  4. Servo rotates sensor $0^\circ$ right, records clearance $D_{\text{right}}$.
  5. Turns chassis toward the direction with larger clearance ($> 30\text{ cm}$) and resumes driving.

---

### 3. Multi-DOF Robotic Arm
* **Directory**: [`projects/robotic-arm/`](projects/robotic-arm/)
* **Microcontroller**: Arduino Mega 2560 or ESP32 NodeMCU
* **Key Components**: PCA9685 16-channel 12-bit I2C PWM driver, 4x MG996R metal-gear servos (base rotation, shoulder, elbow, wrist pitch), 2x SG90/MG90S servos (wrist roll, gripper).
* **Power Requirement**: Dedicated external 5V 10A regulated power supply. Common ground linked to microcontroller.

---

### 4. Quadcopter Drone
* **Directory**: [`projects/drone/`](projects/drone/)
* **Flight Controller**: F4 / F7 Flight Controller running Betaflight (STM32F405 / STM32F722)
* **Key Components**: 4x 2205/2306 2400KV brushless motors, 4-in-1 35A BLHeli_S ESC, 5045 3-blade propellers, 4S 1500mAh 75C LiPo, ELRS 2.4GHz receiver.
* **Safety Protocol**: Always remove propellers before connecting to Betaflight Configurator on the bench.

---

### 5. ESP32 Smart Rover
* **Directory**: [`projects/esp32-robot/`](projects/esp32-robot/)
* **Microcontroller**: ESP32 NodeMCU 32-bit dual-core @ 240MHz
* **Firmware**: [`Robo_ESP32.ino`](projects/esp32-robot/Robo_ESP32.ino)
* **Features**: Bluetooth Serial remote control via smartphone joystick, dual H-bridge motor driving, status indication LED, expandable to WiFi WebSockets and video streaming.

---

## ⚡ Electronics

Files and guides located in [`electronics/`](electronics/).

### Circuits & Prototyping
Located in [`electronics/circuits/`](electronics/circuits/):
- **Universal Grounding**: All independent voltage sources (Li-ion battery pack, 5V USB logic, external 12V motor supply) must share a common GND.
- **Decoupling**: Solder a $100\text{nF}$ ceramic capacitor close to the $V_{CC}$ pin of every IC to filter high-frequency switching transients.
- **Inductive Kickback Protection**: Motors and solenoids generate reverse EMF spikes exceeding $50\text{V}$ when switched off. Ensure motor drivers have internal flyback diodes or install external Schottky diodes (1N5819 / 1N4007).

### Schematics & EDA Standards
Located in [`electronics/schematics/`](electronics/schematics/):
- Use **KiCad** (v7/v8) or **EasyEDA**.
- Net naming rules: Prefix power nets clearly (`+5V`, `+3V3`, `VBAT`, `GND`). Label bus signals (`I2C_SDA`, `I2C_SCL`, `UART_TX`, `UART_RX`, `MOTOR_PWM_A`).
- Always export and commit a high-resolution `.pdf` and `.png` alongside the source schematic files.

### PCB Layout & Manufacturing
Located in [`electronics/pcb/`](electronics/pcb/):
- **Power Traces**: Width $\ge 30\text{ mil}$ ($0.76\text{ mm}$) for currents up to $1.5\text{A}$; $\ge 50\text{ mil}$ for motor rails.
- **Signal Traces**: $8-10\text{ mil}$ with $8\text{ mil}$ minimum spacing.
- **Copper Pours**: Ground planes on both Top and Bottom layers with thermal relief pads for easy hand-soldering.
- Provide standard zip archives containing Gerber files (RS-274X) and Excellon drill files ready for fabrication.

### Component Selection Guide
Located in [`electronics/components/`](electronics/components/):

| Component Category | Part Number | Operating Voltage | Key Specification | Best Used For |
| :--- | :--- | :--- | :--- | :--- |
| **Motor Driver** | L298N | 5V – 35V | 2A continuous / channel | High voltage, rugged prototyping |
| **Motor Driver** | TB6612FNG | 4.5V – 15V | 1.2A continuous (MOSFET) | Low heat, efficient mobile robots |
| **Stepper Driver**| A4988 / DRV8825 | 8V – 45V | Up to 2.5A, 1/32 microstep | 3D printers, robotic arm precision joints |
| **Distance Sensor**| HC-SR04 | 5V | Range: 2cm – 400cm | Obstacle detection rovers |
| **Laser ToF Sensor**| VL53L0X | 2.8V – 5V | Range: 3cm – 200cm | High-speed precision distance measuring |
| **IMU / Gyro** | MPU-6050 | 3.3V – 5V | 6-DOF (Gyro + Accel) I2C | Self-balancing robots, drones |

---

## 💻 Software

Codebases and toolchain resources located in [`software/`](software/).

### Arduino
* **Directory**: [`software/arduino/`](software/arduino/)
* **Toolchain**: Arduino IDE 2.x or PlatformIO on VS Code.
* **Core Practices**:
  - Non-blocking delays: Use `millis()` instead of `delay()` for motor control and telemetry loops.
  - Pin assignments: Declare pins as `constexpr uint8_t PIN_NAME = ...` instead of `#define` to enforce type safety.

### ESP32
* **Directory**: [`software/esp32/`](software/esp32/)
* **Features**:
  - **FreeRTOS Dual-Core Tasks**: Pin heavy networking (WiFi/BLE) to Core 0 and real-time motor control loops to Core 1 via `xTaskCreatePinnedToCore()`.
  - **LEDC Hardware PWM**: ESP32 does not use `analogWrite()`; use the hardware LEDC channel API:
    ```cpp
    ledcAttachPin(MOTOR_PWM_PIN, PWM_CHANNEL);
    ledcSetup(PWM_CHANNEL, 1000 /* 1kHz */, 8 /* 8-bit 0-255 */);
    ledcWrite(PWM_CHANNEL, speed);
    ```

### Raspberry Pi
* **Directory**: [`software/raspberry-pi/`](software/raspberry-pi/)
* **Operating System**: Ubuntu 22.04 LTS Server / Raspberry Pi OS 64-bit.
* **Robotics Middleware**: ROS 2 (Humble / Iron) for distributed node messaging, TF transforms, and SLAM navigation.

### Python
* **Directory**: [`software/python/`](software/python/)
* **Libraries**: `pyserial`, `numpy`, `matplotlib`, `pygame` (for USB game controllers).
* **Usage**: PC-to-robot telemetry dashboards, inverse kinematics solvers, and data logging.

### Computer Vision
* **Directory**: [`software/computer-vision/`](software/computer-vision/)
* **Framework**: OpenCV (C++ / Python).
* **Capabilities**: HSV color segmentation for ball/line tracking, AprilTag / ArUco marker pose estimation, edge detection (`cv2.Canny`), and optical flow.

---

## 🛠️ Mechanical

Mechanical design files located in [`mechanical/`](mechanical/).

### CAD
* **Directory**: [`mechanical/cad/`](mechanical/cad/)
* **Formats**: Parametric CAD in native formats (Autodesk Fusion 360 `.f3d`, SolidWorks `.sldprt`/`.sldasm`) plus universal neutral exchange files (`.STEP`, `.IGES`).

### STL
* **Directory**: [`mechanical/stl/`](mechanical/stl/)
* **3D Printing Parameters**:
  - **Material**: PLA (standard prototypes), PETG (outdoor/shock-resistant), or TPU (flexible tires/bumpers).
  - **Infill**: $20\%-30\%$ Gyroid or Grid infill for chassis brackets; $50\%-100\%$ for high-stress motor mounts and servo horns.
  - **Wall Thickness**: Minimum 3-4 perimeter walls ($1.2\text{ mm} - 1.6\text{ mm}$) for structural stiffness.

### Dimensions
* **Directory**: [`mechanical/dimensions/`](mechanical/dimensions/)
* Reference dimension sheets for standard hardware:
  - TT Geared Motor mounting bolt spacing ($17.5\text{ mm}$ center-to-center).
  - N20 Micro Metal Gear Motor faceplate holes ($M1.6$, $9\text{ mm}$ spacing).
  - SG90 servo dimensions ($22.8\text{ mm} \times 12.2\text{ mm} \times 28.5\text{ mm}$).
  - 18650 Li-ion 2-cell holder footprint ($76\text{ mm} \times 40\text{ mm}$).

### Drawings
* **Directory**: [`mechanical/drawings/`](mechanical/drawings/)
* 2D vector files (`.dxf`, `.svg`, `.pdf`) for laser cutting $3\text{ mm}$ / $5\text{ mm}$ acrylic, MDF, or aluminum sheet chassis.

---

## 📚 Documentation

Guides and troubleshooting located in [`documentation/`](documentation/).

### Tutorials & Setup Guides
* [**`documentation/tutorials/`**](documentation/tutorials/): Beginner guides covering breadboard wiring, writing your first Arduino sketch, reading analog sensors, and controlling motor direction with H-bridges.
* [**`documentation/setup-guides/`**](documentation/setup-guides/): Step-by-step installation guides for Arduino IDE, CH340 / CP2102 USB-to-UART drivers, PlatformIO, and ROS 2.

### Troubleshooting Matrix
Located in [`documentation/troubleshooting/`](documentation/troubleshooting/):

| Symptom / Issue | Likely Cause | Solution |
| :--- | :--- | :--- |
| **Microcontroller resets when motors turn on** | Voltage drop (brownout) from motor inrush current. | Power motors from an independent battery pack. Add a $470\mu\text{F}$ capacitor across motor driver power input. |
| **Motors do not spin, but buzz loudly** | Insufficient voltage or PWM frequency too high. | Verify battery voltage under load. Set PWM frequency between $1\text{kHz} - 4\text{kHz}$ and increase minimum duty cycle. |
| **I2C sensor hangs or returns 0 / 255** | Missing pull-up resistors or address conflict. | Add $4.7\text{k}\Omega$ pull-up resistors on SDA/SCL lines. Run an I2C scanner sketch to verify bus address. |
| **Servo vibrates and jitters continuously** | Shared logic power line or weak current. | Power servos from external 5V regulator. Never power more than one micro servo directly from an Arduino 5V pin. |

---

## 🧰 Resources

Reference materials located in [`resources/`](resources/).

### Microcontroller Pinout Reference

#### ESP32 NodeMCU (30-Pin Standard)
```text
                  +-------------------+
            EN ---| 1              30 |--- GPIO23 (VSPI_MOSI)
      GPIO36 (VP) ---| 2              29 |--- GPIO22 (I2C_SCL)
      GPIO39 (VN) ---| 3              28 |--- GPIO1  (UART0_TX)
          GPIO34 ---| 4              27 |--- GPIO3  (UART0_RX)
          GPIO35 ---| 5              26 |--- GPIO21 (I2C_SDA)
          GPIO32 ---| 6              25 |--- GND
          GPIO33 ---| 7              24 |--- GPIO19 (VSPI_MISO)
          GPIO25 ---| 8              23 |--- GPIO18 (VSPI_SCK)
          GPIO26 ---| 9              22 |--- GPIO5  (VSPI_CS)
          GPIO27 ---| 10             21 |--- GPIO17 (UART2_TX)
          GPIO14 ---| 11             20 |--- GPIO16 (UART2_RX)
          GPIO12 ---| 12             19 |--- GPIO4
             GND ---| 13             18 |--- GPIO0  (BOOT)
          GPIO13 ---| 14             17 |--- GPIO2  (Built-in LED)
             Vin ---| 15             16 |--- GPIO15
                  +-------------------+
```

#### Arduino Nano
- **Digital I/O**: Pins `D0` to `D13` (PWM: `D3`, `D5`, `D6`, `D9`, `D10`, `D11`)
- **Analog Inputs**: Pins `A0` to `A7` (10-bit ADC, $0-5\text{V}$)
- **I2C Bus**: `A4` (SDA), `A5` (SCL)
- **SPI Bus**: `D10` (SS), `D11` (MOSI), `D12` (MISO), `D13` (SCK)
- **UART**: `D0` (RX), `D1` (TX)

### Datasheets & Links
Located in [`resources/datasheets/`](resources/datasheets/) and [`resources/useful-links/`](resources/useful-links/):
- [Wokwi Online Arduino/ESP32 Simulator](https://wokwi.com/)
- [Falstad Circuit Simulator](https://www.falstad.com/circuit/)
- [KiCad Official EDA](https://www.kicad.org/)
- [Betaflight Configurator](https://github.com/betaflight/betaflight-configurator)

---

## 🤝 Contributing & Community

We encourage contributions from all members! Please review our:
- [**Contributing Guide**](CONTRIBUTING.md) for pull request formatting, git conventions, and style rules.
- [**Code of Conduct**](CODE_OF_CONDUCT.md) for community participation standards.
- [**License**](LICENSE) for open-source terms (MIT License).

<p align="center">
  <b>🤖 Robotics Club</b><br>
  <sub>Think • Engineer • Innovate</sub>
</p>
