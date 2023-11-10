#include <stdio.h>
#include <string.h>

int main() {
	char text[50], c;
	int freq=0, i=0;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(text);
	printf("Enter a character to find frequency: ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &c);
	while(i<strlen(text))
	{
		if(c==text[i])
		{
			freq +=1;
		}
		i++;
	}
	printf("Frequency of %c = %d", c, freq);
	return 0;
}
