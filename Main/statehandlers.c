#include "stateCtxt.h:"

/* Define behaviour to given set of inputs */
STATE State1(FsmT *fsm, void *pvEvent)
{   
    STATE nextState;
    /* do some state specific behaviours 
     * here
     */
    /* fsm->currentState currently contains the previous state
     * just before it gets updated, so you can implement behaviours 
     * which depend on previous state here
     */
    fsm->currentState = '1';
    /* Now, specify the next state
     * to transition to, or return null if you're still waiting for 
     * more stuff to process.  
     */
    switch (fsm->signal)
    {
        case eEnter:
            nextState = State2;
            break;
        case eNormal:
            nextState = null;
            break;
        case eExit:
            nextState = State2;
            break;
    }

    return nextState;
}

STATE  State3(FsmT *fsm, void *pvEvent)
{
    /* do some state specific behaviours 
     * here
     */
    fsm->currentState = '2';
    /* Now, specify the next state
     * to transition to
     */
     return State1;
}

STATE   State2(FsmT *fsm, void *pvEvent)
{   
    /* do some state specific behaviours 
     * here
     */
    fsm->currentState = '3';
    /* Now, specify the next state
     * to transition to
     */
     return State3;
}
