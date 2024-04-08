#include "CA.h"
#include "US.h"
#include "DC.h"

void setup ()
{
	//Init all drivers
	//Init IRQ
	//Init HAL: US driver, DC driver
	//Init Block
	US_init ();
	DC_init ();
	//Set state pointers for each block
	CA_state = waiting;
	US_state = USbusy;
	DC_state = DCidle;
}

int main ()
{
	volatile int d;
	setup();
	while (1)
	{
		/*Using the pointers to call each block*/
		CA_state();
		US_state();
		DC_state();
		for (d=0; d<10000000; d++); //delay
	}
	return 0;
}
