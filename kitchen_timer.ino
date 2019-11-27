#include "enpitshield.h"
#include "led3.h"
#include "led1.h"
#include "kitchen_timer.h"
int Kitchen_Timer_Count;//タイマー初期値
int Onesec_Count;//一秒をカウントする
int Kitchen_Timer_Alarm_Count;//アラームの１５秒をカウント
int Kitchen_TimerState;
boolean bAlarm_entry;

int isKitchen_TimerState(){
  return Kitchen_TimerState;
}
void Kitchen_Timer_Init(){
  Kitchen_TimerState=KITCHEN_TIMER_OFF;
  Kitchen_Timer_Count=30;
  Onesec_Count=0;//0.25秒を４回カウントして１秒とする
  Kitchen_Timer_Alarm_Count=15;
  bAlarm_entry=true;

  return;
}
void Kitchen_Timer_Tick025(){
  ++Onesec_Count;
  if(Onesec_Count>=4){//4回呼ばれたら、すなわち一秒間隔
    Kitchen_Timer();
    Onesec_Count=0;
  }
  return;
}
void Kitchen_Timer(){
  switch(Kitchen_TimerState){
    case  KITCHEN_TIMER_OFF:
      Timer_OffBlink();
      break;
    case  KITCHEN_TIMER_ON:
      Timer_OnBlink();
      break;
    case  KITCHEN_TIMER_ALARM:
      TimerAlarmBlink();
      break;
  }
}

void Timer_OnBlink(){
  if(Kitchen_Timer_Count>0){
    --Kitchen_Timer_Count;
  }else{
    //タイムアップ
    Kitchen_Timer_Set(KITCHEN_TIMER_ALARM);
    Kitchen_Timer_Count=30;
  }
  return;
}

void Timer_OffBlink(){
  //何もしない
  return;
}

void Timer_CountChenge(){
    if(Kitchen_Timer_Count==30){
      Kitchen_Timer_Count=60;
      Led1_ON();
    }else{
      Kitchen_Timer_Count=30;
      Led1_OFF();
    }
  return;
}

int getTimer_Count(){
  return Kitchen_Timer_Count;
}

void TimerAlarmBlink(){
//  if(bAlarm_entry){//Led3点灯開始
//    bAlarm_entry=false;
//  }
  
  --Kitchen_Timer_Alarm_Count;
  if(Kitchen_Timer_Alarm_Count<=0){
    Kitchen_Timer_Set(KITCHEN_TIMER_OFF);
    //bAlarm_entry
  }
  return;
}

void Kitchen_Timer_Set(int blink){
  Kitchen_TimerState=blink;
  switch(blink){
    case  KITCHEN_TIMER_OFF:
      Kitchen_Timer_Init();
      Led1_OFF();
      Led3_Set(BLINK_OFF);
      break;
    case  KITCHEN_TIMER_ON:
      Led3_Set(BLINK_COUNT);
      break;
    case  KITCHEN_TIMER_ALARM:
      Led3_Set(BLINK_ALARM);
      break;
  }
  return;
}
