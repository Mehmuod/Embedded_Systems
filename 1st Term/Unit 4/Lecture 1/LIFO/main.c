#include "LIFO.h"

unsigned int buffer1 [5]; //20Bytes

int main(){
	unsigned int i, temp=0;
	LIFO_Buffer_t UART_lifo, I2C_lifo;
	//Static Allocation
	LIFO_Init(&UART_lifo, buffer1, 5);
	//Dynamic Allocation
	unsigned int* buffer2 = (unsigned int*) malloc (5 * sizeof(unsigned int)); //Also 20Bytes but dynamic
	LIFO_Init(&I2C_lifo, buffer2, 5);

	for (i=0; i<5; i++)
		if (LIFO_Add_Item(&UART_lifo, i) == LIFO_no_error)
			printf("UART_lifo add = %d\n", i);

	for (i=0; i<5; i++){
		if (LIFO_Get_Item(&UART_lifo, &temp) == LIFO_no_error)
			printf("UART_lifo get = %d\n", temp);
	}
	return 0;
}
