# Windows Setup Guide: AVR Toolchain & Microchip Studio

This guide will help you set up your Windows PC for embedded C development with the ATmega328P microcontroller.

---


> **Note:** You only need to install **either** Microchip Studio **or** the AVR-GCC toolchain, not both. Choose the one that fits your workflow:
> - **Microchip Studio**: Recommended for beginners and those who prefer a graphical IDE (Windows only).
> - **AVR-GCC Toolchain**: For command-line, Makefile-based, or cross-platform development.

## 1. Choose Your Setup

### Option 1: Microchip Studio (Recommended)
1. Download [Microchip Studio](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio).
2. Run the installer and follow the prompts.
3. After installation, open any `.atsln` project from the `microchip-studio/` folder.
4. Select device **ATmega328P**, build, and flash to your board.

---

### Option 2: AVR-GCC Toolchain (Command Line)

#### Option A: AVR-GCC from Microchip
1. Download the [AVR 8-bit Toolchain for Windows](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers-avr).
2. Run the installer and add the toolchain to your system PATH.

#### Option B: WinAVR (Legacy)
1. Download [WinAVR](http://winavr.sourceforge.net/).
2. Install and ensure `avr-gcc` and `avrdude` are in your PATH.

---

## 2. Install avrdude (Flashing Tool)

1. avrdude is included with WinAVR and some AVR-GCC packages.
2. If not, download a Windows build from [avrdude releases](https://github.com/avrdudes/avrdude/releases).
3. Add the folder containing `avrdude.exe` to your PATH.

---

## 3. USBasp Driver Installation

1. Download [Zadig](https://zadig.akeo.ie/).
2. Plug in your USBasp programmer.
3. Open Zadig, select `USBasp` from the list, and install the `libusb-win32` driver.

---

## 4. Test Your Setup

1. Open Command Prompt (Win+R, type `cmd`).
2. Run:
	```sh
	avr-gcc --version
	avrdude -?
	```
	You should see version info for both tools.

---

## 5. Build and Flash an Example

1. Open a terminal in an example folder, e.g. `examples/00_blink`.
2. Run:
	```sh
	make flash
	```
3. The LED should blink if everything is set up correctly!

---

## Troubleshooting

- If `avr-gcc` or `avrdude` are not recognized, check your PATH.
- For USBasp issues, reinstall the driver with Zadig.
- For permission errors, try running as administrator.

---

Happy coding on Windows! 🚀
