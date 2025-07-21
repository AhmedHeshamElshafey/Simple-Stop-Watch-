# 🕒 ATmega32 Stopwatch with Time-Sharing Concept
## 📷Proteus simulation:
### ✅Before Working:
![Stopwatch Preview](./Image/Stop%20Watch.png)
### ✅After Working:
![Stopwatch Preview](./Image/Stop%20Watch%20Working.png)
## 📌 Project Overview:
- This project implements a countdown stopwatch using an ATmega32 microcontroller and two 7-segment displays. The stopwatch is configurable, supports pause/resume, reset, and time editing, and alerts when time runs out. A key feature of this project is the time-sharing (multiplexing) technique used to reduce the number of required I/O pins for driving the displays.

## 🔧 Features
- **⏱ Countdown Timer**: Starts from a default time and decrements every second.

- **⏸ Pause/Resume Button**: Toggle between running and paused states.

- **🔁 Reset Button**: Instantly resets the timer to the last configured value.

- **⚙️ Configuration Mode:**

      _ Press configuration button once to edit the ones digit and First Digit Led be on and second Digit Led be off  .

      _ Press again to edit the tens digitand Second Digit Led be on and first Digit Led be off.

      _ Use pause to increment and reset to decrement.

- **🔔 Alarm Indication**: When time reaches 0, both LED indicators blink.

**🔁 Time Multiplexing**: Only one pin per 7-segment display is used by rapidly alternating (time-sharing) control between digits, saving MCU pins.

## 🧠 Time-Sharing (Multiplexing) Concept:
- Instead of using a separate set of pins for each 7-segment digit, this project:
Activates one display at a time using control pins (SEVENSEGMANT_1, SEVENSEGMANT_2).
Rapidly switches between the two displays every few milliseconds using _delay_ms().
This switching is fast enough that both digits appear to be on simultaneously to the human eye.
- Saves microcontroller I/O resources by sharing the same segment lines.

## 📁 File Structure:
```
├── MCAL/
│   └── DIO/               # Digital I/O functions
├── HAL/
│   └── SEVEN_SEGMENT/     # Seven segment driver
├── MCU/Atmega32_REGS.h    # Register definitions
├── STD_HEADERS/
│   ├── BITMATH.h
│   └── STD_TYPES.h
└── main.c                 # Main stopwatch logic
```

## ⚙️ Hardware Used:
✅ ATmega32 Microcontroller (8MHz)

✅ Two 7-Segment Displays (Common Cathode/Anode)

✅ Push Buttons (Pause/Resume, Reset, Configure)

✅ LEDs for visual indication

✅ Resistors and wires

## 🔘 Buttons and Pins:
```
Function                	Pin
7-Seg Select 1          	PINB0
7-Seg Select 2                  PINB1
Pause/Resume            	PINB6
Reset                   	PINB7
Configure	                PINB5
Digit 1 LED             	PINB3
Digit 2 LED	                PINB4
```
## 🚦 Operating Instructions:
- **Startup**: Countdown begins from default 30 seconds.

- **Pause/Resume**: Press the pause button once to pause, press again to resume.

- **Reset**: Press reset to revert to last configured time.

- **Configure**:

    - Press config once → edit ones digit.

    - Press again → edit tens digit.

    - Use pause to increase and reset to decrease.

    - Press config again to exit editing mode.

## 📣 Notes:
- The project showcases efficient pin usage by using only one pin per 7-segment display for digit selection.

- Real-time button debounce is managed via **flag toggling logic**
