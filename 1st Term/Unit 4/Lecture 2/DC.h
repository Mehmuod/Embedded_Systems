#ifndef DC_H_
#define DC_H_

#include <stdio.h>
#include <stdlib.h>

/*Defining states*/
enum
{
	DC_idle,
	DC_busy
}DC_State_ID;

/*CA state functions declarations*/
void DC_init ();
void DCMotor (int s);
void DCidle ();
void DCbusy ();

extern void (*DC_state)();

#endif /* DC_H_ */
