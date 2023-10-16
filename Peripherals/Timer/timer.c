#include "timer.h"


volatile bool timer_flag = false;

/**
 * brief: Timer handler, when timer runs out, execute
 * part of nrf5 app_timer 
*/
static void repeated_timer_handler(void * p_context)
{
    timer_flag = !(timer_flag);
}

/**
 * brief: Start low frequency clock, needed when not
 * using softdevice
*/
static timer_error lfclk_request()
{
    ret_code_t err_code = nrf_drv_clock_init();
    
    if (err_code != NRF_SUCCESS)
    {
        return TIMER_ERROR;
    }
    nrf_drv_clock_lfclk_request(NULL);

    return TIMER_GOOD;
}

// TODO: pass in function for timer handler, need help with function pointers
timer_error timer_init()
{
    if (lfclk_request() != TIMER_GOOD)
    {
        return TIMER_LFCLK_INIT_ERROR;
    }

    if (app_timer_init() != NRF_SUCCESS)
    {
        return TIMER_APP_INIT_ERROR;
    }

    return TIMER_GOOD;
}

// TODO: How to make this more general to make multiple timers?
timer_error timer_create()
{
    ret_code_t err_code;

    err_code = app_timer_create(&m_repeated_timer_id,
                                APP_TIMER_MODE_REPEATED,
                                repeated_timer_handler);
    
    if (err_code != NRF_SUCCESS)
    {
        return TIMER_CREATE_ERROR;
    }

    return TIMER_GOOD;
}

timer_error timer_start(uint8_t time_ms)
{
    ret_code_t err_code;
    
    err_code = app_timer_start(m_repeated_timer_id, APP_TIMER_TICKS(time_ms), NULL);
    
    if (err_code != NRF_SUCCESS)
    {
        return TIMER_START_ERROR;
    }

    return TIMER_GOOD;
}