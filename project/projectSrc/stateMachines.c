#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void redOn()//turn red led on with sound
{
  buzzer_set_period(1500);
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void greenOn()//turn green led on with sound
{
  buzzer_set_period(1000);
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
}

void onlySound()//turn both leds off with sound
{
  buzzer_set_period(2000);
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void doNothing()//turn everything off
{
  buzzer_set_period(0);
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}

void state_advance()
{
  switch(b){
  case 1:
    redOn();
    break;
  case 2:
    greenOn();
    break;
  case 3:
    onlySound();
    break;
  case 4:
    doNothing();
    break;
  }
}
