#include <stdint.h>

extern int main(void);
void reset_Handler ();
void NMI_Handler () __attribute__ ((weak, alias("default_Handler"))); ;
void H_fault_Handler () __attribute__ ((weak, alias("default_Handler"))); ;

void default_Handler () {
	reset_Handler();
}

/*Booking 1024 bytes located by .bss through unintialized array of 256 int elements (256*4=1024)*/
static unsigned long stackTop_arr [256]; //'static' to prevent this variable from being used anywhere outside this file.

extern unsigned _E_text;
extern unsigned _S_data;
extern unsigned _E_data;
extern unsigned _S_bss;
extern unsigned _E_bss;
extern unsigned _Stack_Top;

volatile unsigned g_bssVar;
void (*g_p_fn_Vectors []) () __attribute__ ((section(".vectors"))) =
{
	(void(*) ()) (unsigned long)stackTop_arr + sizeof(stackTop_arr),
	&reset_Handler,
	&NMI_Handler,
	&H_fault_Handler	
};

void reset_Handler () {
	/*Copying .data section from FLASH to RAM*/
	unsigned int data_Size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* p_src = (unsigned char*)&_E_text;
	unsigned char* p_dst = (unsigned char*)&_S_data;
	unsigned i;
	for (i=0; i<data_Size; i++)
	{
		*(p_dst++) = *(p_src++);
	}
	/*Initializing .bss section in SRAM = 0*/
	unsigned bss_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	p_dst = (unsigned char*)&_S_bss;
	for (i=0; i<bss_Size; i++)
	{
		*((unsigned char*)p_dst++) = (unsigned char)0;
	}
	/*Branching to main()*/	
	main ();
}