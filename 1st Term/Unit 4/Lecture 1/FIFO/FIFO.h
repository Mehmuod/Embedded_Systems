#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>

/*User configurations*/
/*Element type selection*/
#define element_type uint8_t //uint8_t, uint16_t, uint32_t, ...

/*Buffer creation*/
#define width1 5
element_type UART_Buffer[width1];

/*FIFO data type*/
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_empty,
	FIFO_full,
	FIFO_null
}FIFO_buf_status;

/*FIFO APIs prototypes*/
FIFO_buf_status FIFO_Init (FIFO_buf_t* fifo, element_type* buffer, uint32_t length);
FIFO_buf_status FIFO_Enqueue (FIFO_buf_t* fifo, element_type item);
FIFO_buf_status FIFO_Dequeue (FIFO_buf_t* fifo, element_type* item);
FIFO_buf_status FIFO_is_Full (FIFO_buf_t* fifo);
void FIFO_Print (FIFO_buf_t* fifo);

#endif /* FIFO_H_ */
