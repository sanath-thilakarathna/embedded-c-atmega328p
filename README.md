# Embedded C with ATmega328P

Learn **Embedded C programming** with the ATmega328P microcontroller (the same MCU used in Arduino Uno).  
This repository provides **step-by-step examples, reusable drivers, and small projects** to build a strong foundation in embedded systems.

---

## 🚀 Features
- 📘 Beginner-friendly examples from **Blink** to advanced peripherals.  
- 🛠️ Supports both **Microchip Studio (Windows)** and **avr-gcc/avrdude (cross-platform)**.  
- 🔌 Covers GPIO, timers, interrupts, ADC, UART, SPI, I²C, EEPROM, watchdog, and sleep modes.  
- 📦 Includes **HAL (Hardware Abstraction Layer)** and simple drivers for common modules.  
- 🌱 Mini-projects to integrate multiple peripherals into real applications.  
- 🔓 Free for everyone under the **MIT License**.

---

## 📂 Repository Structure
embedded-c-atmega328p/
├─ README.md
├─ LICENSE
├─ toolchains/ # Setup guides + Makefile template
├─ docs/ # Quick start, syllabus, diagrams
├─ libs/ # HAL + reusable drivers
├─ examples/ # Step-by-step learning codes
├─ projects/ # Small integrated applications
├─ programming/ # avrdude + programmer wiring guides
└─ microchip-studio/ # Example .atsln/.cproj projects


---

## 🧑‍💻 Quick Start ([Full Guide](docs/quick-start.md))

### Option 1: Microchip Studio (Windows)
1. Install [Microchip Studio](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio).
2. Open any `.atsln` file under `microchip-studio/`.
3. Select device **ATmega328P**, build, and flash to board.

### Option 2: avr-gcc + avrdude (Cross-platform)
1. Install AVR toolchain (`avr-gcc`, `avr-libc`, `avrdude`).
2. Navigate to an example, e.g.:
   ```bash
   cd examples/00_blink
   make flash
   ```

---

## 📚 Learning Path

- **GPIO** — LED blink, button input, debouncing
- **Timers** — delays, PWM for LED/servo
- **Interrupts** — external & timer ISRs
- **ADC** — read sensors, scaling values
- **UART** — serial communication & printf
- **SPI** — OLED, SD card basics
- **I²C (TWI)** — RTC, MPU6050
- **EEPROM** — read/write non-volatile memory
- **Watchdog & Sleep** — power saving and resets
- **Mini-Projects** — greenhouse controller, data logger, LCD menus

---

## 🔧 Hardware Requirements

- ATmega328P board (Arduino Uno or bare chip on breadboard)
- USBasp programmer or Arduino as ISP
- Breadboard, LEDs, buttons, resistors, potentiometer
- Optional: LCD (HD44780), RTC (DS3231), temperature sensors, etc.

---

## 📜 License


---

## 📖 Documentation & Guides

- [Quick Start Guide](docs/quick-start.md)
- [Syllabus](docs/syllabus.md)
- [Windows Setup](toolchanins/windows-setup.md)
- [macOS Setup](toolchanins/macos-setup.md)
- [Linux Setup](toolchanins/linus-setup.md)
- [avrdude Cheatsheet](programming/avrdude-cheatsheet.md)

---

This project is licensed under the **MIT License**.
You are free to use, modify, and share with proper attribution.