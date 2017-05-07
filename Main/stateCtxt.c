#include "stateCtxt.h"
#include "statehandlers.h"

typedef STATE (*pfnStateT)(FsmSignalT signal, void *pvEvent);

static FsmT      fsm;
static pfnStateT UsbState ;

int STATECTXT_Init(void)
{    
    UsbState = State1;
    fsm.signal = eEnter;
    // use an enum for better maintainability
    fsm.currentState = '1';
    (*UsbState)( &fsm, pvEvent);
    return 0;
}

static void ChangeState( FsmT *pFsm, pfnStateT targetState )
{
    // Check to see if the state has changed
    if (targetState  != NULL)
    {
        // Call current state's exit event
        pFsm->signal = eExit;
        STATE dummyState = (*UsbState)( pFsm, pvEvent);

        // Update the State Machine structure
        UsbState = targetState ;

        // Call the new state's enter event
        pFsm->signal = eEnter;            
        dummyState = (*UsbState)( pFsm, pvEvent);
    }
}

void STATECTXT_Handle(void *pvEvent)
{
    pfnStateT newState;

    if (UsbState != NULL)
    {
         fsm.signal = eNormal;
         newState = (*UsbState)( &fsm, pvEvent );
         ChangeState( &fsm, newState );
    }        
}


void STATECTXT_Set(StateT  stateID)
{
     prevState = UsbState;
     switch (stateID) 
     {
         case '1':               
            ChangeState( State1 );
            break;
          case '2':
            ChangeState( State2);
            break;
          case '3':
            ChangeState( State3);
            break;
     }
}
