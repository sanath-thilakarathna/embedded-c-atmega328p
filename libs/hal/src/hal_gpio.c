/* --------------------------------------------------------------------------
 * hal_gpio.c — GPIO HAL implementation for ATmega328P
 * -------------------------------------------------------------------------- */
#include "../include/hal_gpio.h"

/* Rationale:
 * - For outputs, set level first (PORTx) then set DDRx bit to 1 → avoids glitches.
 * - For inputs, clear DDRx bit to 0 then set/clear PORTx to control pull-up.
 * - Toggle uses write-1-to-PINx for atomicity (no read-modify-write race).
 */

void gpio_init(const gpio_t *g, gpio_dir_t dir, bool initial_high)
{
    if (dir == GPIO_OUTPUT) {
        /* Set level first to avoid momentary spikes when switching to output */
        if (initial_high) *(g->port) |=  (uint8_t)(1u << g->bit);
        else              *(g->port) &= ~(uint8_t)(1u << g->bit);
        /* Now make it an output */
        *(g->ddr) |= (uint8_t)(1u << g->bit);
    } else {
        /* Make it input */
        *(g->ddr) &= ~(uint8_t)(1u << g->bit);
        /* Control pull-up via PORTx */
        if (initial_high) *(g->port) |=  (uint8_t)(1u << g->bit);  /* pull-up on */
        else              *(g->port) &= ~(uint8_t)(1u << g->bit);  /* pull-up off */
    }
}

void gpio_set_dir(const gpio_t *g, gpio_dir_t dir)
{
    if (dir == GPIO_OUTPUT) *(g->ddr)  |=  (uint8_t)(1u << g->bit);
    else                    *(g->ddr)  &= ~(uint8_t)(1u << g->bit);
}

void gpio_pullup(const gpio_t *g, bool enable)
{
    if (enable) *(g->port) |=  (uint8_t)(1u << g->bit);
    else        *(g->port) &= ~(uint8_t)(1u << g->bit);
}

void gpio_write(const gpio_t *g, bool high)
{
    if (high) *(g->port) |=  (uint8_t)(1u << g->bit);
    else      *(g->port) &= ~(uint8_t)(1u << g->bit);
}

void gpio_toggle(const gpio_t *g)
{
    /* Atomic toggle on AVR: writing '1' to PINx toggles corresponding PORT bit */
    *(g->pin) = (uint8_t)(1u << g->bit);
}

bool gpio_read(const gpio_t *g)
{
    return ((*(g->pin)) & (uint8_t)(1u << g->bit)) != 0;
}
