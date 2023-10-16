#include "LED.h"

void LED_init()
{
    nrf_gpio_cfg_output(LED_BLINK);
    nrf_gpio_cfg_output(LED_BLINK_BUTTON);
}

void LED_blink()
{
    nrf_gpio_pin_toggle(LED_BLINK);
}

void LED_blink_button()
{
    nrf_gpio_pin_toggle(LED_BLINK_BUTTON);
}