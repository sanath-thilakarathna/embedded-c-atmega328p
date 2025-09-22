/* --------------------------------------------------------------------------
 * hal_gpio.h — GPIO HAL for ATmega328P (no hardcoded pins)
 * --------------------------------------------------------------------------
 * Usage:
 *   #include "hal_gpio.h"
 *   GPIO_DEF(LED,   DDRB, PORTB, PINB, PB5);     // you choose the pins
 *   GPIO_DEF(BUTTON,DDRD, PORTD, PIND, PD2);
 *
 *   gpio_init(&LED, GPIO_OUTPUT, false);          // output, start LOW
 *   gpio_init(&BUTTON, GPIO_INPUT, true);         // input, pull-up enabled
 *   gpio_toggle(&LED);
 *   bool pressed = !gpio_read(&BUTTON);           // active-low button
 *
 * Notes:
 *   - No dynamic allocation, no globals.
 *   - Implementations in hal_gpio.c.
 *   - Works with both F_CPU=16 MHz and 8 MHz (clock doesn’t affect GPIO).
 * -------------------------------------------------------------------------- */
#pragma once

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* A pin is described by its DDR/PORT/PIN register addresses and bit index. */
typedef struct {
    volatile uint8_t *ddr;   /* DDRx */
    volatile uint8_t *port;  /* PORTx */
    volatile uint8_t *pin;   /* PINx */
    uint8_t           bit;   /* 0..7 (e.g., PB5) */
} gpio_t;

/* Helper to declare a gpio_t at file scope.
 * Example: GPIO_DEF(LED, DDRB, PORTB, PINB, PB5); */
#define GPIO_DEF(name, DDRx, PORTx, PINx, BIT) \
    static const gpio_t name = { &(DDRx), &(PORTx), &(PINx), (BIT) }

/* Direction */
typedef enum {
    GPIO_INPUT  = 0,
    GPIO_OUTPUT = 1
} gpio_dir_t;

/* --- API ---------------------------------------------------------------- */

/** Configure direction and initial state.
 *  - If dir == GPIO_OUTPUT: `initial_high` sets the output level before enabling output.
 *  - If dir == GPIO_INPUT : `initial_high` enables internal pull-up when true.
 */
void gpio_init(const gpio_t *g, gpio_dir_t dir, bool initial_high);

/** Change direction later (does not alter pull-up or output level). */
void gpio_set_dir(const gpio_t *g, gpio_dir_t dir);

/** Enable/disable internal pull-up (only meaningful when configured as input). */
void gpio_pullup(const gpio_t *g, bool enable);

/** Write logic level (meaningful when configured as output). */
void gpio_write(const gpio_t *g, bool high);

/** Toggle output using atomic PINx write-1-to-toggle. */
void gpio_toggle(const gpio_t *g);

/** Read logic level from PINx (works regardless of direction). */
bool gpio_read(const gpio_t *g);

/* Optional convenience shortcuts */
static inline void gpio_make_output(const gpio_t *g, bool initial_high) {
    gpio_init(g, GPIO_OUTPUT, initial_high);
}
static inline void gpio_make_input(const gpio_t *g, bool pullup_on) {
    gpio_init(g, GPIO_INPUT, pullup_on);
}

#ifdef __cplusplus
}
#endif
