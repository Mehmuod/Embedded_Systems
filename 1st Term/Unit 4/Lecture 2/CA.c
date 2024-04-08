#include "CA.h"

/*Variables definitions*/
int CA_speed, CA_distance, CA_threshold = 50;

void (*CA_state)(); //Pointer to function

void US_setDistance (int d)
{
	CA_distance = d;
	CA_distance <= CA_threshold? (CA_state = waiting) : (CA_state = driving);
	printf("Ultrasonic ========distance=%d=========> CA\n", CA_distance);
}

void waiting ()
{
	//state name
	CA_State_ID = _waiting;
	printf("CA Waiting... Distance = %d\t Speed = %d\n", CA_distance, CA_speed);
	//state action
	CA_speed = 0;
	DCMotor (CA_speed);
}

void driving ()
{
	//state name
	CA_State_ID = _driving;
	printf("CA Driving... Distance = %d\t Speed = %d\n", CA_distance, CA_speed);
	//state action
	CA_speed = 30;
	DCMotor (CA_speed);
}
