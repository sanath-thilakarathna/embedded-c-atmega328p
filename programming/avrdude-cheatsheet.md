# AVRDude Command Line Cheatsheet

AVRDude is a command-line utility to program AVR microcontrollers. This cheatsheet covers basic usage, common options, and practical examples for the ATmega328P.

---

## Basic Syntax

```
avrdude -c <programmer> -p <partno> -P <port> -b <baudrate> -U <memtype>:<op>:<filename>[:<format>]
```

- `-c <programmer>`: Programmer type (e.g., `usbasp`, `arduino`, `avrisp`)
- `-p <partno>`: AVR device (e.g., `m328p` for ATmega328P)
- `-P <port>`: Port (e.g., `COM3` on Windows, `/dev/ttyUSB0` on Linux)
- `-b <baudrate>`: Baud rate (e.g., `115200`)
- `-U`: Memory operation (see below)

---

## Common Memory Operations

- Flash: `-U flash:w:main.hex:i` (write)
- EEPROM: `-U eeprom:w:data.eep:i` (write)
- Read flash: `-U flash:r:backup.hex:i`
- Verify: `-U flash:v:main.hex:i`

---

## Examples

### 1. Write a HEX file to ATmega328P using USBasp
```
avrdude -c usbasp -p m328p -U flash:w:main.hex:i
```

### 2. Write a HEX file using Arduino as ISP (on COM3, 115200 baud)
```
avrdude -c arduino -p m328p -P COM3 -b 115200 -U flash:w:main.hex:i
```

### 3. Read flash memory to a file
```
avrdude -c usbasp -p m328p -U flash:r:backup.hex:i
```

### 4. Verify flash after writing
```
avrdude -c usbasp -p m328p -U flash:v:main.hex:i
```

---

## Useful Options

- `-v` : Verbose output
- `-B <bitclock>` : Set bit clock period (for slow targets)
- `-F` : Override signature check (use with caution)
- `-n` : No write (test only)

---

## List Supported Programmers
```
avrdude -c ?
```

## List Supported Parts
```
avrdude -p ?
```

---

## References
- [AVRDude Documentation](https://www.nongnu.org/avrdude/user-manual/avrdude.html)
- [AVRDUDE Programmer Types](https://www.nongnu.org/avrdude/user-manual/avrdude.html#Programmers)
