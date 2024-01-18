# include <stdio.h>

int main(){
	unsigned int m = 29;
	unsigned int* ab = NULL;

	printf("Address of m: %p", &m);
	printf("\nValue of m: %u", m);

	ab = &m;
	printf("\n\nAddress of pointer ab: %p", ab);
	printf("\nContent of pointer ab: %u", *ab);

	m=34;
	printf("\n\nAddress of pointer ab: %p", ab);
	printf("\nContent of pointer ab: %u", *ab);

	*ab=7;
	printf("\n\nAddress of m: %p", &m);
	printf("\nValue of m: %u", m);

	return 0;
}
