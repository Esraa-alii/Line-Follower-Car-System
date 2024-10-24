# Line Follower Car System

This project is an embedded system application designed for a line follower car. The car follows a predefined path using two IR sensors, which detect whether the car is on the line or needs to adjust its direction. The system controls the car’s motion using DC motors based on the sensor inputs.

## Features

- **Stop**: The car stops if neither IR sensor detects the line (both sensors read `0`).
- **Turn Right**: The car turns right if the right sensor detects the line (`IR1 = 1`) and the left sensor does not (`IR2 = 0`).
- **Turn Left**: The car turns left if the left sensor detects the line (`IR1 = 0`) and the right sensor does not (`IR2 = 1`).
- **Move Forward**: The car moves forward when both sensors detect the line (`IR1 = 1` and `IR2 = 1`).

## Project Structure

- **`DIO`**: Manages digital input/output operations for the microcontroller's pins.
- **`DCMOTOR`**: Controls the direction and movement of the motors based on sensor input.
- **`IR Sensors`**: Detect the line and provide signals to the microcontroller.

## Code Overview

The code initializes the microcontroller's pins and motor control. It continuously checks the readings from two IR sensors, then adjusts the car's movement accordingly by controlling the DC motors.

### Main Loop

- **IR Sensor Readings**: The system reads the values of two IR sensors using `DIO_u8ReadpinVal()`.
- **Motor Control**:
  - When neither sensor detects the line, the car stops both motors.
  - When only the right sensor detects the line, the car turns right.
  - When only the left sensor detects the line, the car turns left.
  - When both sensors detect the line, the car moves forward.

## Hardware Requirements

- **Microcontroller**: Capable of reading digital inputs and controlling DC motors (e.g., AVR, PIC, STM32).
- **DC Motors**: For driving the wheels of the car.
- **Motor Driver**: To interface between the microcontroller and the motors.
- **IR Sensors**: For detecting the line.

## How to Use

1. **Setup the microcontroller** with the required hardware (IR sensors, DC motors, motor driver).
2. **Compile and flash** the provided code onto the microcontroller.
3. Adjust the car's movement by ensuring the IR sensors are correctly aligned with the line. The car will:
   - Stop when off the line.
   - Turn right or left to adjust to the line.
   - Move forward when both sensors are on the line.


