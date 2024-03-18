#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
/*Type Definitions*/
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buffer_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_null
}LIFO_Status;

/*APIs Prototypes*/
LIFO_Status LIFO_Init (LIFO_Buffer_t* lifo_buf, unsigned int* buf, unsigned length);
LIFO_Status LIFO_Add_Item (LIFO_Buffer_t* lifo_buf, unsigned int item);
LIFO_Status LIFO_Get_Item (LIFO_Buffer_t* lifo_buf, unsigned int* item);


#endif /* LIFO_H_ */
