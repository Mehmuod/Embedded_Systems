#include <stdio.h>

struct Student
{
	char name [30];
	int rollNum;
	float  marks;
};

struct Student getInfo()
{
	struct Student s;
	printf("Enter name: ");
	fflush(stdout);
	scanf("%s", s.name);

	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d", &s.rollNum);

	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f", &s.marks);

	return s;
}

void printInfo(struct Student s)
{
	printf("\nDisplaying Information: \n");
	printf("name: %s\n", s.name);
	printf("roll: %d\n", s.rollNum);
	printf("marks: %.2f", s.marks);
}

int main() {
	struct Student pupil;
	printf("Enter information of students: \n\n");
	pupil = getInfo();
	printInfo(pupil);

    return 0;
}
