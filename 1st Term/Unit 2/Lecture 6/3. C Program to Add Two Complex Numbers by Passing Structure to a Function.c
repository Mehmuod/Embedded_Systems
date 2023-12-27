#include <stdio.h>
#include <math.h>

struct sComplex
{
	float r;
	float  i;
} c1, c2;

struct sComplex getComplex()
{
	struct sComplex c;

	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f", &c.r, &c.i);

	return c;
}

void addComplex(struct sComplex c1, struct sComplex c2)
{
	struct sComplex sum;
	sum.r = c1.r + c2.r;
	sum.i = c1.i + c2.i;

	printf("\nSum = %.1f + %.1fi", sum.r, sum.i);
}

int main() {
	printf("For 1st complex number: \n");
	c1 = getComplex();
	printf("\nFor 2nd complex number: \n");
	c2 = getComplex();

	addComplex(c1, c2);

    return 0;
}
