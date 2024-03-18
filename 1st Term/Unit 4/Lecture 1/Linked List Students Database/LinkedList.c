#include "LinkedList.h"

struct s_student* gp_1stStudent = NULL;

void add_student()
{
	struct s_student* pNew;
	struct s_student* pNavigate;
	char temp_text [30];

	/*Empty list check*/
	if (gp_1stStudent == NULL)
	{
		pNew = (struct s_student*) malloc (sizeof(struct s_student));
		gp_1stStudent = pNew;
	}
	else
	{
		pNavigate = gp_1stStudent;
		while (pNavigate->pNext)
			pNavigate = pNavigate->pNext;
		pNew = (struct s_student*) malloc (sizeof(struct s_student));
		pNavigate->pNext = pNew;
	}
	/*Filling the student's records*/
	puts("Enter the student's ID");
	fflush(stdout); fflush(stdin);
	gets(temp_text);
	pNew->student.ID = atoi(temp_text);

	puts("Enter the full name");
	fflush(stdout); fflush(stdin);
	gets(pNew->student.name);

	puts("Enter the student's height");
	fflush(stdout); fflush(stdin);
	gets(temp_text);
	pNew->student.height = atof(temp_text);

	/*Set the pointer of the latest student to NULL*/
	pNew->pNext = NULL;
	puts("-.-.-Student added successfully-.-.-");
}

int remove_student()
{
	unsigned id;
	/*Empty list check*/
	if (gp_1stStudent)
	{
		puts("Enter the student's ID that you wish to remove.");
		fflush(stdout); fflush(stdin);
		scanf("%u", &id);
		struct s_student* pSelect = gp_1stStudent;
		struct s_student* pPrecede = NULL;
		/*Looping on all records*/
		while (pSelect)
		{
			/*Comparing each node with the selected ID*/
			if (pSelect->student.ID == id){
				if (pPrecede) //The selected student is not the 1st as the pPrecede then would be = NULL.
				{
					pPrecede->pNext = pSelect->pNext;
				}
				else //The 1st student is the one selected.
				{
					gp_1stStudent = pSelect->pNext; //gp_1stStudent = gp_1stStudent->pNext
				}
				free (pSelect);
				puts("-.-.-Student removed successfully-.-.-");
				return 1;
			}
			pPrecede = pSelect;
			pSelect = pSelect->pNext;
		}
		puts ("No matching ID.");
	}
	else
		puts("List is empty.");
	return 0;
}

void view_students ()
{
	struct s_student* pCurrent = gp_1stStudent;
	unsigned count = 0;
	if (gp_1stStudent == NULL)
		puts("List is empty.");
	else
	{
		while (pCurrent)
		{
			printf ("Record #%u", count+1);
			printf ("\n\t Student's ID: %u", pCurrent->student.ID);
			printf ("\n\t Student's Name: %s", pCurrent->student.name);
			printf ("\n\t Height: %.2f\n", pCurrent->student.height);
			pCurrent = pCurrent->pNext;
			count++;
		}
	}
}

void deleteAll ()
{
	struct s_student* pCurrent = gp_1stStudent;
	if (gp_1stStudent == NULL)
		puts("List is empty.");
	else
	{
		while (pCurrent)
		{
			struct s_student* pTemp = pCurrent;
			pCurrent = pCurrent->pNext;
			free (pTemp);
		}
		gp_1stStudent = NULL;
	}
	puts("-.-.-List cleared-.-.-");
}

void printNode(struct s_student* node)
{
    printf ("\n\t Student's ID: %u", node->student.ID);
    printf ("\n\t Student's Name: %s", node->student.name);
    printf ("\n\t Height: %.2f\n", node->student.height);
}

void getNth()
{
	struct s_student* pNth = gp_1stStudent;
	int count = 1, n;

	if (gp_1stStudent == NULL)
	{
		puts("List is empty.");
		return;
	}

    puts("Enter the student's record number you wish to view");
    fflush(stdout); fflush(stdin);
    scanf("%d", &n);

	while (n <= 0)
	{
		puts("Invalid Input.");
		puts("Please re-enter a valid node number.");
		fflush(stdout); fflush(stdin);
		scanf("%u", &n);
	}

	while (pNth)
	{
		if (n == count)
		{
			printNode(pNth);
			return;
		}
		else
		{
			pNth = pNth->pNext;
			count++;
		}
	}
    /*If loop completes without finding nth student*/
    puts("Node number out of range.");
}

void getLength_i()
{
	unsigned counter = 0;
	struct s_student* pNavigator = gp_1stStudent;

	if (gp_1stStudent == NULL)
	{puts("List is empty."); return;}

	while (pNavigator)
	{
		pNavigator = pNavigator->pNext;
		counter++;
	}
	printf("The number of students in the list is %u\n", counter);
}

/*int getCount()
{
	static unsigned int counter = 0;
	static struct s_student* pHead = NULL;
    static int initialized = 0;  // Flag to track pHead initialization

     Initialize pHead only once
    if (!initialized) {
        pHead = gp_1stStudent;
        initialized = 1;
    }
	if (pHead)
	{
		counter++;
		pHead = pHead->pNext;
		getCount();
	}
	return counter;
}*/

void getLength_r()
{
	struct s_student* pHead = gp_1stStudent;
	unsigned num = getCount(pHead);
	printf("The number of students is =  %u\n", num);
}


int getCount(struct s_student* head)
{
  /* Base Case */
  if (head == NULL)
    return 0;
  else
    /* Recursive case: Move to next node and add 1 to the count */
    return (1 + getCount(head->pNext));
}


void getLastNthNode()
{
	if (gp_1stStudent == NULL)
	{puts("List is empty."); return;}

	/*Finding the number of nodes in the linked list*/
	struct s_student* navigator = gp_1stStudent;
	unsigned int len = getCount(navigator);
	int n, i;

    puts("Enter the student's record number from the end that you wish to view");
    fflush(stdout); fflush(stdin);
    scanf("%d", &n);

    for(i=1; i<(len-n+1); i++){
    	navigator = navigator->pNext;}

	printNode(navigator);
}

void findNthNodeFromEnd()
{
	if (gp_1stStudent == NULL)
	{puts("List is empty."); return;}

	struct s_student *reference, *Main;
	reference = Main = gp_1stStudent;
	int i, n;

    puts("Enter the nth student record number from the end");
    fflush(stdout); fflush(stdin);
    scanf("%d", &n);

	for (i=1; i<=n; i++)
		reference = reference->pNext;

	while(reference)
	{
		Main = Main->pNext;
		reference = reference->pNext;
	}
	printNode(Main);
}

void getMiddle()
{
	if (gp_1stStudent == NULL)
	{puts("List is empty."); return;}

	struct s_student *pSlow, *pFast;
	pSlow = pFast = gp_1stStudent;

	while (pFast && pFast->pNext) //Be careful, 'while (pFast->pNext && pFast)' results in a segmentation fault.
	{
		pSlow = pSlow->pNext;
		pFast = pFast->pNext->pNext;
	}
	printNode(pSlow);
}

void reverse()
{
	if (gp_1stStudent == NULL)
	{puts("List is empty."); return;}

	struct s_student *pCurrent, *pAfter, *pBefore;
	pCurrent = gp_1stStudent;
	pBefore = NULL;

	/*No point reversing if only a single element exists.*/
	if (pCurrent->pNext == NULL)
		return;

	while (pCurrent)
	{
		pAfter = pCurrent->pNext;
		pCurrent->pNext = pBefore;
		pBefore = pCurrent;
		pCurrent = pAfter;
	}
	gp_1stStudent = pBefore; //'Head' now points to the last item in the list.
}
