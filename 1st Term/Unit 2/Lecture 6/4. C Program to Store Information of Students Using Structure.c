#include <stdio.h>

struct sStudent
{
	char name [32];
	int  marks;
}student [10];

void getStudents()
{
	int i=0;

	printf("Enter information of students: \n");
	while (i<10)
	{
		printf("\nFor roll number %d\n", i+1);
		printf("Enter name: ");
		fflush(stdout);
		gets(student[i].name);
		printf("Enter marks: ");
		fflush(stdout);
		scanf("%d", &student[i].marks);
		while (getchar() != '\n');
		i++;
	}
}

void printStudents(struct sStudent student [])
{
	int i=0;

	while (i<10)
	{
		printf("\nInformation for roll number %d: \n", i+1);
		printf("Name: %s\n", student[i].name);
		printf("Marks: %d\n", student[i].marks);
		i++;
	}
}

int main() {
	getStudents();
	printStudents(student);

    return 0;
}
