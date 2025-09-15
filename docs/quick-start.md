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

### OS-specific Setup Guides

- For **Windows**: see [windows-setup.md](../toolchanins/windows-setup.md)
- For **Linux**: see [linux-setup.md](../toolchanins/linux-setup.md)
- For **macOS**: see [macos-setup.md](../toolchanins/macos-setup.md)

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
