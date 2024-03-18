#include "FIFO.h"

int main() {
	element_type i, temp;
	FIFO_buf_t FIFO_UART;
	if (FIFO_Init(&FIFO_UART, UART_Buffer, 5) == FIFO_no_error)
		printf("-.-.-FIFO buffer initialized successfully-.-.-\n");

	for (i=0; i<7; i++)
	{
		printf("\nFIFO enqueue (%x)\n", i);
		if (FIFO_Enqueue(&FIFO_UART, i) == FIFO_no_error)
			printf("\t-.-.-FIFO enqueue complete-.-.-");
		else
			printf("\t-.-.-FIFO enqueue failed-.-.-");
	}
	FIFO_Print(&FIFO_UART);

	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\nFIFO dequeue (%x)", temp);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\nFIFO dequeue (%x)", temp);

	FIFO_Print(&FIFO_UART);

	return 0;
}


