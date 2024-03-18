#include "FIFO.h"
/*FIFO APIs definitions*/
FIFO_buf_status FIFO_Init (FIFO_buf_t* fifo, element_type* buffer, uint32_t length)
{
	if (buffer == NULL)
		return FIFO_null;

	fifo->base = buffer;
	fifo->head = buffer;
	fifo->tail = buffer;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}

FIFO_buf_status FIFO_Enqueue (FIFO_buf_t* fifo, element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	/*FIFO buffer full check*/
	if(FIFO_is_Full(fifo) == FIFO_full)
		return FIFO_full;
	*(fifo->head) = item;
	fifo->count++;
	/*Circular FIFO implementation*/
	if (fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_no_error;
}

FIFO_buf_status FIFO_Dequeue (FIFO_buf_t* fifo, element_type* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	/*FIFO buffer empty check*/
	if (fifo->count == 0)
		return FIFO_empty;

	*item = *(fifo->tail);
	fifo->count--;
	/*Circular FIFO dequeue*/
	if (fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;
}

FIFO_buf_status FIFO_is_Full (FIFO_buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if(fifo->count == fifo->length)
		return FIFO_full;
	return FIFO_no_error;
}

void FIFO_Print (FIFO_buf_t* fifo)
{
	element_type* temp;
	int i;
	if (fifo->count == 0)
		printf("\n-.-.-FIFO is empty-.-.-");
	else
	{
		temp = fifo->tail;
		printf("\n\n===FIFO buffer container===\n");
		for (i=0; i<fifo->count; i++)
		{
			printf("\t%x\n", *temp);
			temp++;
		}
	}
}
