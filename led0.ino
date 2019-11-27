#include "enpitshield.h"

static boolean bCurLed0;
int Led0_count=0;

void Led0_Init(){
  bCurLed0=LED_OFF;
  digitalWrite(LED0,LED_OFF);

  return;
}

void Led0_Tick05(){
  if(bCurLed0==LED_OFF){
    bCurLed0=LED_ON;
  }
  else{
    bCurLed0=LED_OFF;
  }
  digitalWrite(LED0,bCurLed0);
  return;
}
void Led0_Tick025(){
  if(Led0_count<=1){
    bCurLed0=LED_ON;
  }
  else{
    bCurLed0=LED_OFF;
    if(Led0_count>=4){
    }
  }
  ((Led0_count>=4)? Led0_count=0 : ++Led0_count);
  digitalWrite(LED0,bCurLed0);
  return;
}
