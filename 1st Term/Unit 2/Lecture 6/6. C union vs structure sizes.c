#include <stdio.h>
/*#pragma pack(1)*/

union uValue
{
	float f;
	short s;
	char c;
	int name [8];
}u;

struct sValue
{
	float f;
	short s;
	char c;
	int name [8];
}s;

int main(){
	printf("size of union = %d", sizeof(u));
	printf("\nsize of structure = %d", sizeof(s));

	return 0;
}
