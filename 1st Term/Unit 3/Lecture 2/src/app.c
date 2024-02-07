#include <UART.h>

unsigned char string_buffer [100] = "learn-in-depth: Mahmood";
 
void main (void) {
	UART_send_string (string_buffer);
		
}