#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

/* red led is on and buzzer is on while button is not pressed*/
void toggle_red_sound()
{
  red_on = 1;
  green_on = 0;
  led_update();
  buzzer_set_period(1500);
}

void toggle_both_no_sound()
{
  red_on = 0;
  green_on = 0;
  led_update();
  buzzer_set_period(0);
}

void only_sound()
{
  red_on = 0;
  green_on = 0;
  led_update();
  buzzer_set_period(2000);
}

void turn_off()
{
  red_on = 0;
  green_on = 0;
  led_update;
  buzzer_set_period(0);
}
