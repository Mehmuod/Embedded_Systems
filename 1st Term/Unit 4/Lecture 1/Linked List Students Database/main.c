#include "LinkedList.h"

int main() {
	char temp_text [30];

	while (1){
		puts("=====================");
		puts("Choose one of the following options:");
		puts("1: Add a student.");
		puts("2: Remove a student.");
		puts("3: View all students.");
		puts("4: Delete all students.");
		puts("5: View the info of a student based on his order in the list.");
		puts("6: Find the number of students recorded.");
		puts("7: Find the number of students recorded. [RECURSIVELY]");
		puts("8: View the nth student from the end.");
		puts("9: View the nth student from the end. [Double Pointers]");
		puts("10: View the middle student in the list.");
		puts("11: Reverse the order of the list.");
		fflush(stdout); fflush(stdin);
		gets(temp_text);
		puts("=====================");
		switch (atoi(temp_text))
		{
		case 1:
			add_student();
			break;
		case 2:
			remove_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			deleteAll();
			break;
		case 5:
			getNth();
			break;
		case 6:
			getLength_i();
			break;
/*		case 7:
			printf("Number of students are = %d\n", getCount());
			break;*/
		case 7:
			getLength_r();
			break;
		case 8:
			getLastNthNode();
			break;
		case 9:
			findNthNodeFromEnd();
			break;
		case 10:
			getMiddle();
			break;
		case 11:
			reverse();
			break;
		default:
			puts("Invalid Input.");
			break;
		}
	}
	return 0;
}
