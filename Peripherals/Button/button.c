#include "button.h"


// This should be changed to use app_button, which uses gpiote and app_timer for debouncing


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