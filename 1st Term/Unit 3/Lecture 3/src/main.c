#include <stdint.h>
typedef volatile unsigned int vuint32_t;
/*Register Addresses*/
#define RCC_Base			0x40021000
#define GPIOA_Base 		0x40010800
#define RCCAPB2ENR 	*(vuint32_t *) (RCC_Base 		+ 0x18)
#define GPIOA_CRH		*(vuint32_t *) (GPIOA_Base 	+ 0x04)
#define GPIOA_ODR		*(vuint32_t *) (GPIOA_Base 	+ 0x0c)

typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t reserved: 13;
		vuint32_t pin13: 1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*) (GPIOA_Base + 0x0c);
unsigned char g_variables [3] = {1,2,3}; //to increase output data section
unsigned const char const_variables [3] = {1,2,3}; //to create rodata section
unsigned char bss_var [3]; //to create .bss section

int main () {
	int i;
	RCCAPB2ENR |= 1<<2;
	GPIOA_CRH |= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	while (1)
	{
		//GPIOA_ODR |= 1<<13; /*set bit 13*/
		R_ODR -> pin.pin13=1;
		for (i=0; i<5000; i++);
		//GPIOA_ODR &= ~(1<<13); /*clear bit 13*/
		R_ODR -> pin.pin13=0;
		for (i=0; i<5000; i++);
	}
	return 0;
}
