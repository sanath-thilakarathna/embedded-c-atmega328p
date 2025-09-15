# Quick Start Guide: Embedded C with ATmega328P

Welcome! This guide will help you set up your environment and run your first embedded C program on the ATmega328P microcontroller.

---

## 1. Hardware Requirements

- ATmega328P board (Arduino Uno or bare chip)
- USBasp programmer or Arduino as ISP
- Breadboard, LEDs, buttons, resistors, potentiometer
- (Optional) LCD (HD44780), RTC (DS3231), sensors

---

## 2. Software Setup

### Option 1: Microchip Studio (Windows)
1. Download and install [Microchip Studio](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio).
2. Open any `.atsln` project in the `microchip-studio/` folder.
3. Select device **ATmega328P**.
4. Build and flash the project to your board.

### Option 2: avr-gcc + avrdude (Cross-platform)
1. Install AVR toolchain:
   - Windows: [WinAVR](http://winavr.sourceforge.net/) or [AVR-GCC Toolchain](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers-avr)
   - macOS: `brew install avr-gcc avrdude`
   - Linux: `sudo apt install avr-gcc avr-libc avrdude`
2. Navigate to an example:
   ```bash
   cd examples/00_blink
   make flash
   ```

---

## 3. Project Structure Overview

- `examples/` — Step-by-step learning codes (start here!)
- `libs/` — HAL and reusable drivers
- `projects/` — Mini-projects integrating multiple peripherals
- `docs/` — Guides, diagrams, and syllabus

---

## 4. First Program: Blink an LED

1. Wire an LED (with resistor) to a GPIO pin (e.g., PD5/Arduino pin 5).
2. Open `examples/00_blink` in your IDE or terminal.
3. Build and flash as described above.
4. The LED should blink if everything is set up correctly!

---

## 5. Troubleshooting

- Double-check wiring and board selection.
- Ensure drivers for your programmer are installed.
- For permission errors on Linux/macOS, try running `sudo` or adding your user to the `dialout` group.
- Consult the [syllabus](syllabus.md) or README for more help.

---

Happy hacking! 🚀
