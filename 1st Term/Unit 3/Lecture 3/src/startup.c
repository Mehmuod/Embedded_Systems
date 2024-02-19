#include <stdint.h>

extern int main(void);
void reset_Handler ();
void NMI_Handler () __attribute__ ((weak, alias("default_Handler"))); ;
void H_fault_Handler () __attribute__ ((weak, alias("default_Handler"))); ;
void MM_Fault_Handler () __attribute__ ((weak, alias("default_Handler"))); ;
void Bus_Fault () __attribute__ ((weak, alias("default_Handler"))); ;
void Usage_Fault_Handler () __attribute__ ((weak, alias("default_Handler"))); ;

void default_Handler () {
	reset_Handler();
}

extern unsigned _E_text;
extern unsigned _S_data;
extern unsigned _E_data;
extern unsigned _S_bss;
extern unsigned _E_bss;
extern unsigned _Stack_Top;

uint32_t vectors [] __attribute__ ((section(".vectors"))) = {
	(uint32_t) &_Stack_Top,
	(uint32_t) &reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler
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