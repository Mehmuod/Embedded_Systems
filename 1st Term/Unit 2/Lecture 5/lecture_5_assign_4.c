#include <stdio.h>
int exponent(int x, int y);

int main() {
	int base,power;
	puts("Enter an integer base number along with a positive integer exponent: ");
	fflush(stdout);
	scanf("%d %d", &base, &power);
	printf("%d^%d = %d", base, power, exponent(base, power));
	return 0;
}

int exponent(int x, int y){
	static int i=0;
	if (i++<y){
		return x*exponent(x, y);
	}
	else
		return 1;
}
