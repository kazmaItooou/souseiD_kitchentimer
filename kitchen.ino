
#include <MsTimer2.h>
#include "enpitshield.h"
#include "kitchen_timer.h"
#include "LED3.h"
#include "LED1.h"
#include "sw.h"

#define TIMER_CYCLE 250

void setup() {
  pinMode(LED0,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED3,OUTPUT);

  
  Led0_Init();
  Led1_Init();
  Led3_Init();
  switch_init();
  Kitchen_Timer_Init();
  MsTimer2::set(TIMER_CYCLE,interval_Timer025);//250ｍｓごとにオンオフ
  //MsTimer2::set(TIMER_CYCLE,Led0_Tick025);//250ｍｓごとにオンオフ
  //MsTimer2::set(TIMER_CYCLE,Led3_Tick025);//250ｍｓごとにオンオフ
  MsTimer2::start();

  Led3_Set(BLINK_OFF);
}

void loop() {
  switch_toggle();
  switch_mode_select();

  
}
