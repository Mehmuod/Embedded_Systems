#ifndef US_H_
#define US_H_

#include <stdio.h>
#include <stdlib.h>

/*Defining states*/
enum
{
	US_busy
}US_State_ID;

/*CA state functions declarations*/
void US_init ();
void USbusy ();
void US_setDistance (int d);

extern void (*US_state)();

#endif /* US_H_ */
