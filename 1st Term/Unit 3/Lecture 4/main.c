/*Registers Definitions*/
#define SYSCTL_RCGC2_R 		*((volatile unsigned long*) (0x400FE000 + 0x108))
#define GPIO_PORTF_DIR_R 		*((volatile unsigned long*) (0x40025000 + 0x400))
#define GPIO_PORTF_DEN_R 		*((volatile unsigned long*) (0x40025000 + 0x51C))
#define GPIO_PORTF_DATA_R 	*((volatile unsigned long*) (0x40025000 + 0x3FC))

int main () {	
	SYSCTL_RCGC2_R = 0X20;
	/*Delay to make sure that GPIOF is up and running*/
	volatile unsigned delayer; //'volatile' to prevent compiler from removing the 'for' loop in case of optimization enabled.
	for (delayer = 0; delayer < 200; delayer++);
	GPIO_PORTF_DIR_R |= 1<<3; //to set bit#3: dir is o/p for pin#3 in portF
	GPIO_PORTF_DEN_R |= 1<<3; //to enable the GPIO pin
	
	while (1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for (delayer = 0; delayer < 100000; delayer++);
		GPIO_PORTF_DATA_R &= ~(1<<3); //to specifically clear bit#3;
		for (delayer = 0; delayer < 100000; delayer++);
	}	
	return 0;
}