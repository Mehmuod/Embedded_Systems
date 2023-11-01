#include <stdio.h>

void main () {
	char c;
	float x, y;
	printf ("Enter Operator (+, -, *, or /): ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	printf ("Enter two operands: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x, &y);
	switch (c){
	case '+':
		printf ("%.1f + %.1f = %.1f", x, y, x+y);
		break;
	case '-':
		printf ("%.1f - %.1f = %.1f", x, y, x-y);
		break;
	case '*':
		printf ("%.1f x %.1f = %.1f", x, y, x*y);
		break;
	case '/':
		printf ("%.1f / %.1f = %.1f", x, y, x/y);
		break;
	default:
		printf("Invalid Operator");
		break;
	}
}