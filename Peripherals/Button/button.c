#include "button.h"

void button_init()
{
    nrf_gpio_cfg_input(BUTTON, NRF_GPIO_PIN_PULLUP);
}

bool button_press()
{
    if (nrf_gpio_pin_read(BUTTON) == false)
    {
        nrf_delay_ms(50);
        return true;
    }
    else
    {
        return false;
    }
}