#include "DC.h"

/*Variables definitions*/
int DC_speed;

void (*DC_state)(); //Pointer to function

void DC_init ()
{
	/*Initializing PWM driver*/
	puts("PWM initialization complete.");
}

void DCMotor (int s)
{
	DC_speed = s;
	DC_state = DCbusy;
			printf("CA ========speed=%d=========> DC\n", DC_speed);
}

void DCidle ()
{
	//state name
	DC_State_ID = DC_idle;
	printf("DC Idle... Speed = %d\n", DC_speed);
	//state action
	/*Call PWM to set speed = DC_speed*/
}

void DCbusy ()
{
	//state name
	DC_State_ID = DC_busy;
	printf("DC busy... Speed = %d\n", DC_speed);
	DC_state = DCidle;
}







