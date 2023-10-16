#include "app_timer.h"
#include "nrf_drv_clock.h"
#include "nrf_error.h"

APP_TIMER_DEF(m_repeated_timer_id); 

typedef enum
{
    TIMER_ERROR,
    TIMER_GOOD,
    TIMER_UNKNOWN_ERROR,
    TIMER_LFCLK_INIT_ERROR,
    TIMER_APP_INIT_ERROR,
    TIMER_CREATE_ERROR,
    TIMER_START_ERROR
} timer_error;

extern volatile bool timer_flag;


timer_error timer_init();
timer_error timer_create();
timer_error timer_start(uint8_t time_ms);