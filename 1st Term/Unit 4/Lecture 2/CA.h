#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>

/*Defining states*/
enum
{
	_waiting,
	_driving
}CA_State_ID;

/*CA state functions declarations*/
void US_setDistance (int d);
void waiting ();
void driving ();
void DCMotor (int s);

extern void (*CA_state)();

#endif /* CA_H_ */
