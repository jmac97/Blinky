#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"

#include "LED.h"
#include "timer.h"
#include "button.h"

/**
 * GPIO Registers:
 * Offset is 0x514 to set direction
 * Offset is 0x504 to set high/low
 * Offset is 0x508 to read high/low
*/



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
