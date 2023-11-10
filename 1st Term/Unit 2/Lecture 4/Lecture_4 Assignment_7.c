#include <stdio.h>
#include <string.h>

int main() {
	char text[50];
	int i=0, length;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(text);
	while(text[i]!='\0')
	{
		length +=1;
		i++;
	}
	printf("Length of string = %d", length);
	return 0;
}