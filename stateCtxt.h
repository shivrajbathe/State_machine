#define STATE (void *)
typedef enum fsmSignal
{
   eEnter =0,
   eNormal,
   eExit
}FsmSignalT;

typedef struct fsm 
{
   FsmSignalT signal;
   // StateT is an enum that you can define any which way you want
   StateT currentState;
}FsmT;
extern int STATECTXT_Init(void);
/* optionally allow client context to set the target state */
extern STATECTXT_Set(StateT  stateID);
extern void STATECTXT_Handle(void *pvEvent);
