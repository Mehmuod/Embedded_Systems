#include "LIFO.h"
/*APIs Definitions*/
LIFO_Status LIFO_Init (LIFO_Buffer_t* lifo_buf, unsigned int* buf, unsigned length)
{
	if (buf == NULL)
		return LIFO_null;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
}

LIFO_Status LIFO_Add_Item (LIFO_Buffer_t* lifo_buf, unsigned int item)
{
	/*LIFO validity check*/
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_null;

	/*LIFO capacity check*/
	//if (lifo_buf->head >= (lifo_buf->base + (lifo_buf->length * 4)))
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	/*Adding Items*/
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_no_error;
}

LIFO_Status LIFO_Get_Item (LIFO_Buffer_t* lifo_buf, unsigned int* item)
{
	/*LIFO validity check*/
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_null;

	/*Empty LIFO check*/
	if (lifo_buf->count == 0)
		return LIFO_empty;

	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;

}
