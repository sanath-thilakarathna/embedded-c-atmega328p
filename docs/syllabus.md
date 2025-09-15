# Syllabus: Embedded C with ATmega328P

>This syllabus outlines the learning path from basic microcontroller concepts to advanced embedded C programming with the ATmega328P. Each topic includes hands-on examples and mini-projects.

---

## 1. Introduction & Setup
- What is Embedded C?
- Overview of ATmega328P microcontroller
- Hardware & software requirements
- Setting up the toolchain (Microchip Studio, avr-gcc, avrdude)

## 2. GPIO (General Purpose Input/Output)
- Digital output: Blinking an LED
- Digital input: Reading a button
- Debouncing techniques
- Bitwise operations and port manipulation

## 3. Timers & Delays
- Software vs hardware delays
- Timer basics (Timer0, Timer1, Timer2)
- Generating precise delays
- PWM (Pulse Width Modulation) for LED dimming and servo control

## 4. Interrupts
- What are interrupts?
- External interrupts (INT0/INT1)
- Pin change interrupts
- Timer interrupts (overflow, compare match)
- Writing Interrupt Service Routines (ISRs)

## 5. Analog-to-Digital Converter (ADC)
- ADC basics and configuration
- Reading analog sensors (potentiometer, temperature sensor)
- Scaling and interpreting ADC values

## 6. Serial Communication
- UART basics
- Sending and receiving data via UART
- Using printf for debugging
- Serial communication with PC/terminal

## 7. SPI (Serial Peripheral Interface)
- SPI protocol overview
- Master/slave configuration
- Interfacing with SPI devices (OLED, SD card)

## 8. I²C (TWI)
- I²C protocol overview
- Master/slave configuration
- Interfacing with I²C devices (RTC, sensors)

## 9. EEPROM
- Internal EEPROM basics
- Reading and writing non-volatile data

## 10. Watchdog Timer & Sleep Modes
- Watchdog timer for system reliability
- Power-saving sleep modes
- Wake-up sources

## 11. Mini-Projects
- Greenhouse controller (sensors + actuators)
- Data logger (sensors + EEPROM/SD card)
- LCD menu system
- Real-time clock with alarms

---

## Resources
- [Quick Start Guide](quick-start.md)
- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf)
- [AVR Libc Documentation](https://www.nongnu.org/avr-libc/user-manual/)

---

Happy learning and building! 🚀
