#include <stdio.h>

struct sMeasures
{
	int feet;
	float  inches;
};

struct sMeasures getMeasures()
{
	struct sMeasures m;

	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d", &m.feet);

	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f", &m.inches);

	return m;
}

void addDistances(struct sMeasures a, struct sMeasures b)
{
	struct sMeasures sum;
	sum.feet = a.feet + b.feet;
	sum.inches = a.inches + b.inches;

	if (sum.inches >= 12.0)
	{
		sum.feet++;
		sum.inches -= 12;
	}
	printf("\nSum of distances = %d' %.2f''", sum.feet, sum.inches);
}

int main() {
	struct sMeasures distance1;
	struct sMeasures distance2;

	printf("Enter information for 1st distance: \n");
	distance1 = getMeasures();
	printf("\nEnter information for 2nd distance: \n");
	distance2 = getMeasures();

	addDistances(distance1, distance2);

    return 0;
}
