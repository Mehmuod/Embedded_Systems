#include <stdio.h>

int main() {
	float a[10];
	float sum;
	int num, i;

	printf("Enter at most 10 numbers of data: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num);
	while(num>10 || num<=0)
	{
		printf ("Invalid input. \n");
		printf ("Please renter a valid number: ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&num);
	}
	for(i=0;i<num;i++)
	{
		printf("%d.Enter number: ", i+1);
		fflush(stdout); fflush(stdin);
		scanf("%f", &a[i]);
		sum+=a[i];
	}
	printf("average = %.2f", sum/num);
	return 0;
}