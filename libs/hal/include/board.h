/* --------------------------------------------------------------------------
 * board.h — Global board configuration for ATmega328P
 * --------------------------------------------------------------------------
 * Supports two common setups:
 *   - Arduino Uno (16 MHz external crystal)
 *   - Bare ATmega328P @ 8 MHz internal oscillator
 *
 * To select at compile time:
 *   avr-gcc ... -DBOARD_UNO
 *   avr-gcc ... -DBOARD_BARE_8MHZ
 *
 * If nothing is defined, defaults to Arduino Uno.
 * -------------------------------------------------------------------------- */

#pragma once
#include <avr/io.h>

/* ====================== Clock configuration ============================ */
#if defined(BOARD_UNO)
#  define F_CPU 16000000UL   /* 16 MHz external crystal */
#elif defined(BOARD_BARE_8MHZ)
#  define F_CPU 8000000UL    /* 8 MHz internal RC */
#else
#  define F_CPU 16000000UL   /* default fallback: Uno */
#endif

/* ====================== UART defaults ================================= */
#define UART_BAUD    9600UL   /* can be bumped to 115200 if desired */

/* ====================== ADC defaults ================================== */
#define ADC_DEFAULT_REF 1     /* AVcc reference */
#if F_CPU == 16000000UL
#  define ADC_PRESCALER 7     /* /128 → 125 kHz ADC clock */
#elif F_CPU == 8000000UL
#  define ADC_PRESCALER 6     /* /64  → 125 kHz ADC clock */
#endif

/* ====================== Timer defaults ================================ */
#if F_CPU == 16000000UL
#  define TIMER0_PRESCALER 64
#  define TIMER1_PRESCALER 64
#  define TIMER2_PRESCALER 64
#elif F_CPU == 8000000UL
#  define TIMER0_PRESCALER 64
#  define TIMER1_PRESCALER 64
#  define TIMER2_PRESCALER 64
#endif

/* ====================== Fixed hardware pin mappings =================== */
/* UART, I2C, SPI → dictated by silicon, don’t change */
#define UART_RX_BIT  PD0
#define UART_TX_BIT  PD1
#define I2C_SDA_BIT  PC4
#define I2C_SCL_BIT  PC5
#define SPI_MOSI_BIT PB3
#define SPI_MISO_BIT PB4
#define SPI_SCK_BIT  PB5
#define SPI_SS_BIT   PB2
