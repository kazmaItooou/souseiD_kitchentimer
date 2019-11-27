#include "enpitshield.h"
#include "LED1.h"
static boolean bCurLed1;


void Led1_Init(){
  bCurLed1=LED_OFF;
  digitalWrite(LED1,LED_OFF);

  return;
}

void Led1_ON(){
  digitalWrite(LED1,LED_ON);
  return;
  
}

void Led1_OFF(){
  digitalWrite(LED1,LED_OFF);
  return;
  
}
