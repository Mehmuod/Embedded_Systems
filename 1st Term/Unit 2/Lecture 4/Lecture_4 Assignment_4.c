#include <stdio.h>

int main() {
	float a[20];
	int n, i, e, l;
	printf("Enter no of elements between 1 and 20 : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);
	while(n<=0||n>20)
	{
		printf("please reenter a valid choice.");
		fflush(stdin); fflush(stdout);
		scanf("%d", &n);
	}
	for (i=0;i<n;i++)
	scanf("%f", &a[i]);
	for(i=0;i<n;i++)
	printf("%.2f ",a[i]);

	printf("\n\nEnter the element to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &e);
	printf("Enter the location: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &l);

	for(i=n;i>=l;i--)
	a[i] = a[i - 1];

	n++;
	a[l-1]=e;
	for(i=0;i<n;i++)
	printf("%.2f ",a[i]);
	return 0;
}