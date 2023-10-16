#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"

#include "LED.h"
#include "timer.h"
#include "button.h"

// button turns on led, interrupt + debounce



/**
 * @brief Function for application main entry.
 */
int main(void)
{

    timer_init();
    timer_create();
    timer_start(LED_BLINK_TIME);
    LED_init();
    button_init();

    while (1)
    {
        if (timer_flag)
        {
            LED_blink();
            timer_flag = false;
        }

        if (button_press())
        {
            LED_blink_button();
        }
    }

}

/**
 *@}
 **/
