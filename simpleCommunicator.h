/**
	simpleCommunicator.h

	This file automatically generated by FSMLang
*/

#ifndef _SIMPLECOMMUNICATOR_H_
#define _SIMPLECOMMUNICATOR_H_

#ifdef SIMPLE_COMMUNICATOR_DEBUG
#include <stdio.h>
#include <stdlib.h>
#endif

#define FSM_VERSION "1.26"

#define RUN_STATE_MACHINE(A,B) \
	((*(A)->fsm)((A),(B)))

#ifndef INIT_FSM_DATA
#define INIT_FSM_DATA {0}
#endif
#define DECLARE_SIMPLE_COMMUNICATOR_MACHINE(A) \
SIMPLE_COMMUNICATOR (A) =\
{\
	simpleCommunicator_IDLE,\
	&simpleCommunicator_action_array,\
	simpleCommunicatorFSM\
};\
SIMPLE_COMMUNICATOR *p##A = &A;

/* Event naming convenience macros. */
#undef THIS
#define THIS(A) simpleCommunicator_##A
typedef enum {
	 simpleCommunicator_SEND_MESSAGE
	, simpleCommunicator_ACK
	, simpleCommunicator_noEvent
	, simpleCommunicator_numEvents
} SIMPLE_COMMUNICATOR_EVENT;

#ifdef SIMPLE_COMMUNICATOR_DEBUG
extern char *SIMPLE_COMMUNICATOR_EVENT_NAMES[];
#endif

typedef enum {
	 simpleCommunicator_IDLE
	, simpleCommunicator_AWAITING_ACK
	, simpleCommunicator_numStates
} SIMPLE_COMMUNICATOR_STATE;

#ifdef SIMPLE_COMMUNICATOR_DEBUG
extern char *SIMPLE_COMMUNICATOR_STATE_NAMES[];
#endif

typedef struct _simpleCommunicator_struct_ SIMPLE_COMMUNICATOR, *pSIMPLE_COMMUNICATOR;
extern SIMPLE_COMMUNICATOR simpleCommunicator;

extern pSIMPLE_COMMUNICATOR psimpleCommunicator;

typedef SIMPLE_COMMUNICATOR_EVENT (*SIMPLE_COMMUNICATOR_ACTION_FN)(pSIMPLE_COMMUNICATOR);

typedef void (*SIMPLE_COMMUNICATOR_FSM)(pSIMPLE_COMMUNICATOR,SIMPLE_COMMUNICATOR_EVENT);

void simpleCommunicatorFSM(pSIMPLE_COMMUNICATOR,SIMPLE_COMMUNICATOR_EVENT);

typedef struct _simpleCommunicator_action_trans_struct_ {
	SIMPLE_COMMUNICATOR_ACTION_FN	action;
	SIMPLE_COMMUNICATOR_STATE	transition;
} SIMPLE_COMMUNICATOR_ACTION_TRANS, *pSIMPLE_COMMUNICATOR_ACTION_TRANS;

extern const SIMPLE_COMMUNICATOR_ACTION_TRANS simpleCommunicator_action_array[simpleCommunicator_numEvents][simpleCommunicator_numStates];

struct _simpleCommunicator_struct_ {
	SIMPLE_COMMUNICATOR_STATE					state;
	SIMPLE_COMMUNICATOR_ACTION_TRANS const	(*actionArray)[simpleCommunicator_numEvents][simpleCommunicator_numStates];
	SIMPLE_COMMUNICATOR_FSM						fsm;
};

SIMPLE_COMMUNICATOR_EVENT simpleCommunicator_sendMessage(pSIMPLE_COMMUNICATOR);
SIMPLE_COMMUNICATOR_EVENT simpleCommunicator_queueMessage(pSIMPLE_COMMUNICATOR);
SIMPLE_COMMUNICATOR_EVENT simpleCommunicator_checkQueue(pSIMPLE_COMMUNICATOR);
SIMPLE_COMMUNICATOR_EVENT simpleCommunicator_noAction(pSIMPLE_COMMUNICATOR);



#endif
