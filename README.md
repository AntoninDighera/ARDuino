# ARduino_Pidestal_base_2.2

Software to control the base plate of the camera using Arduino Uno 

### Related repositories

## Schematics

## Branches

## Dependencies

### Hardware

- Opto Endstop RRS-OE
- Adafruit Motor Shield v2.3
- Arduino Uno
- Motor

### Software

- Adafruit_MotorShield.h
- IDE used - Arduino 1.8.2

## Setup

Software is verified then uploaded using the Arduino IDE connented to the computer va a USB type A to USB type B cable.
The light sensor must be in contact with the rim of the notched disk on the shaft of the motor.

## Tests / Usage

Red and Blue buttons control the motion of the motor. When the light sensor hits the notch it automatically moves the motor in the reverse direction.
This prevents the motor from moving over 360 deg of motion and provides some feedback so that the user knows that they have gone too far.

## Contact
