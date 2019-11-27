#define KITCHEN_TIMER_OFF 0
#define KITCHEN_TIMER_ON 1
#define KITCHEN_TIMER_ALARM 2

int isKitchen_TimerState();//キッチンタイマー状態を返す
int getTimer_Count();
void Kitchen_Timer_Init();
void Kitchen_Timer_Tick025();
void Kitchen_Timer();
void Timer_OnBlink();
void Timer_OffBlink();
void Timer_CountChenge();
void TimerAlarmBlink();
void Kitchen_Timer_Set(int blink);
