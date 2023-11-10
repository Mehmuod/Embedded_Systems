#include <stdio.h>
#include <string.h>

int main() {
	char text[100], reverse[100];
	int i, length;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(text);
	length = strlen(text);
	for(i=0;text[i]!='\0';++i)
	{
		reverse[i]=text[length-1];
		length--;
	}
	reverse[strlen(text)]='\0';
	printf("reverse string is: %s", reverse);
	return 0;
}