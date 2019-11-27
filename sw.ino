#include "sw.h"
#include "enpitshield.h"
#include "kitchen_timer.h"
boolean bsw0;
boolean bsw1;
boolean bbeforeSw1;
boolean bbeforeSw0;

void switch_init(){
  bsw1=false;
  bsw0=false;
  bbeforeSw0=false;
  bbeforeSw1=false;
}
void switch_toggle(){
  if(digitalRead(SW0)==TACTSW_ON){
    delay(20);
    bsw0=true;
    
  }else {
    bsw0=false;
    bbeforeSw0=false;
  }
  if(digitalRead(SW1)==TACTSW_ON){
    delay(20);
    bsw1=true;
  }else {
    bsw1=false;
    bbeforeSw1=false;
  }
}

void switch_mode_select(){
  if(bsw0 && bbeforeSw0==false){
    bbeforeSw0=true;
    if(isKitchen_TimerState()==KITCHEN_TIMER_OFF){//停止→タイマーの起動中
      Kitchen_Timer_Set(KITCHEN_TIMER_ON);
      
    }else if(isKitchen_TimerState()==KITCHEN_TIMER_ON){//タイマーの起動中→停止
      Kitchen_Timer_Set(KITCHEN_TIMER_OFF);
      
    }else if(isKitchen_TimerState()==KITCHEN_TIMER_ALARM){//アラーム→停止
      Kitchen_Timer_Set(KITCHEN_TIMER_OFF);
    }
  }


  if(bsw1 && bbeforeSw1==false && isKitchen_TimerState()==KITCHEN_TIMER_OFF){
    bbeforeSw1=true;
    Timer_CountChenge();
  }
  
}
