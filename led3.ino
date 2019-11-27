#include "enpitshield.h"
#include "LED3.h"
static boolean bCurLed3;

int Led3State;
int Led3Count;

void Led3_Init(){
  bCurLed3=LED_OFF;
  Led3Count=0;
  Led3State=BLINK_OFF;
  digitalWrite(LED3,LED_OFF);

  return;
}

void Led3_Tick025(){

 switch(Led3State){
  case  BLINK_COUNT://カウント(タイアーが動いてる間)
    Led3_CountBlink();
    break;
    
  case  BLINK_ALARM://アラーム
    Led3_AlermBlink();
    break;

  case  BLINK_OFF://停止状態に戻るときは，LED３の点滅は停止してLED3を消灯する
    Led3_Off();
    break;
 }
  return;
}

void Led3_CountBlink(){
  if(Led3Count%2 && Led3Count<4){
    digitalWrite(LED3,LED_ON);
  }else{
    digitalWrite(LED3,LED_OFF);
  }
  ++Led3Count;
  if(Led3Count>19){
    Led3Count=0;
  }
  return;
}

void Led3_AlermBlink(){
  if(Led3Count%2 && Led3Count){
    digitalWrite(LED3,LED_ON);
  }else{
    digitalWrite(LED3,LED_OFF);
  }
  ++Led3Count;
  if(Led3Count>60){
    Led3State=BLINK_OFF;
  }
  return;
}

void Led3_Off(){
  digitalWrite(LED3,LED_OFF);
  Led3Count=0;
  return;
}
void Led3_Set(int blink){//Led3の状態
  Led3State=blink;
  return;
}
