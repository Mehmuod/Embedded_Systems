# include <stdio.h>

int main(){
	unsigned char alphabet [27];
	unsigned char* ptr = alphabet;
	int i;

	for(i=0; i<26; i++)
	{
		*ptr = i + 'A';
		ptr++;
	}
	ptr = alphabet;

	for(i=0; i<26; i++)
	{
		printf("%c ", *ptr);
		ptr++;
	}

	return 0;
}
