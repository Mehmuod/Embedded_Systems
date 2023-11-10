#include <stdio.h>

int main() {
	int a[20], n, i, s;
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
	scanf("%d", &a[i]);

	printf("Enter the element to be searched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &s);

	i=0;
	while(s!=a[i] && i<n)
	{
		i++;
	}
	if(i!=n)
	printf("Number found at the location = %d", i+1);
	else
		printf("number not found within the array");
	return 0;
}
