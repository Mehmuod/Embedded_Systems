#include <stdio.h>
int primeCheck(int x);

int main() {
	int a, b, check, i;
	puts("Enter two numbers(intervals) :");
	fflush(stdout);
	scanf("%d %d",&a,&b);
	printf ("Prime numbers between %d and %d are: ", a, b);
	for(i=a+1; i<b; i++){
		check=primeCheck(i);
		if (check==0) 	/* if the number is prime */
			printf("%d ", i);
	}
	return 0;
}

int primeCheck(int x){
	int i, check=0;
	/* as long as check=0, ∴ the number is prime */
	for(i=2; i<=x/2; i++)
	{
		if(x%i==0){
			check++; /* the number is indeed not prime */
			break;
		}
	}
	return check;
}
