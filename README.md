# MiniSumoBot

![MiniSumoBot](https://i.imgur.com/ttdAXIv.jpg)

[Robot-sumo](https://en.wikipedia.org/wiki/Robot-sumo), or pepe-sumo, is a sport in which two robots attempt to push each other out of a circle (in a similar fashion to the sport of sumo). The robots used in this competition are called sumobots.  

For detecting the margin of the circle, the robot uses an IR sensor. If that sensor feels that the robot will leave the arena, the control logic will send a sequence of commands to the motor driver so that the robot will return into the arena.

## Software Design

### Sending signal to motors
Pins used: `PB3, PB4` (timer 0) and  `PD6, PD7` (timer 1) using PWM.
Timer sends '1' on `A` and `B` channels and '0' when it gets to `TOP`

### IR Sensor
When the IR sensor detects a white zone, it sends `1` to `PA6` pin. Then, the logic unit is informed to turn the robot and it decides accordingly.

### Bootloader
The `.c` program must be compiled with `make` command. Then, the binary file is uploaded using `./bootloadHID.2019-04-16/gui/HIDBootFlash.exe`. This tool was tested on Windows 10.

## Hardware Design
### Parts
 * Custom Motherboard
 * ATMEGA324A-PU Microcontroller [[1]](https://ocw.cs.pub.ro/courses/_media/pm/doc8272.pdf)
 * Motor Driver [[2]](https://www.optimusdigital.ro/ro/drivere-de-motoare-cu-perii/145-driver-de-motoare-dual-l298n.html)
 * Motors [[3]](https://www.optimusdigital.ro/ro/robotica-kit-uri-de-roboti/140-kit-robot-2-motoare.html)
 * IR Module [[4]](https://www.optimusdigital.ro/ro/senzori-senzori-optici/2415-modul-senzor-infrarou-de-linie-cu-sensibilitate-reglabila.html)
 * Wheels
 * Batteries
 * Breadboard

## Keep on coding!
