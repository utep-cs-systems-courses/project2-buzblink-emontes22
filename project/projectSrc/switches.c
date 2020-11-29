#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed, b; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char button_1 = (p2val & SW1) ? 0 : SW1;
  char button_2 = (p2val & SW2) ? 0 : SW2;
  char button_3 = (p2val & SW3) ? 0 : SW3;
  char button_4 = (p2val & SW4) ? 0 : SW4;

  if(button_1){
    b = 1;
  }
  if(button_2){
    b = 2;
  }
  if(button_3){
    b = 3;
  }
  if(button_4){
    b = 4;
  }

}
