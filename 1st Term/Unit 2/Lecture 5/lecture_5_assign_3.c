#include <stdio.h>
void reverse();

int main() {
	puts("Enter a sentence: ");
	fflush(stdout);
	reverse();
	return 0;
}

void reverse(){
	char c;
	c = getchar();
	if(c!='\n')
		reverse();
	putchar(c);
}
