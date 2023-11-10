#include <stdio.h>

int main(void) {
	float a[2][2];
	float b[2][2];
	int r,c;

	printf("enter the elements of the 1st matrix: \r\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++){
			printf("Enter a%d%d: ", r+1,c+1);
			fflush(stdout); fflush(stdin);
			scanf("%f", &a[r][c]);
		}
	}
	printf("\nenter the elements of the 2nd matrix: \r\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++){
			printf("Enter b%d%d: ", r+1,c+1);
			fflush(stdout); fflush(stdin);
			scanf("%f", &b[r][c]);
		}
	}
	printf("\nSum of the two matrices:\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++){
			printf("%2.2f\t", a[r][c]+b[r][c]);
		}
		printf("\r\n");
	}
}