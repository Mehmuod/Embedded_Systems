#include "US.h"

int getRandDistance (int l, int r, int count);
/*Variables definitions*/
int US_distance;

void (*US_state)(); //Pointer to function

void US_init ()
{
	/*Initializing Ultrasonic driver*/
	puts("Ultrasonic initialization complete.");
}

void USbusy ()
{
	//state name
	US_State_ID = US_busy;
	//state action
	US_distance = getRandDistance(45,55,1);
	//event check

	printf("Ultrasonic busy... Distance = %d\n", US_distance);
	US_setDistance (US_distance);
	US_state = USbusy;
}

int getRandDistance (int l, int r, int count)
{
	int i;
	for (i=0; i<count; i++){
		int rand_num = (rand() % (r-l+1))+l;
		return rand_num;
	}
	return 0;
}








