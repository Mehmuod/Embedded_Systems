# include <stdio.h>

int main(){
	unsigned char str [32]= "string";
	unsigned char* ptr = str;
	unsigned char revstr [32];
	int i=0;

	printf("%s", str);
	while (*ptr)
	{
		ptr++;
		i++;
	}

	int j=0;
	while (i >= 1)
	{
		ptr--;
		revstr[j] = *ptr;
		j++,		i--;
	}
	revstr[j] = '\0';
	printf("\nReversed String: %s", revstr);

	return 0;
}
