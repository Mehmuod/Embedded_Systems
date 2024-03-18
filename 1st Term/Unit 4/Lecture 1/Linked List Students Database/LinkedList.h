#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct s_data {
	int ID;
	char name [30];
	float height;
};

struct s_student {
	struct s_data student;
	struct s_student* pNext;
};

/*Linked list APIs prototypes*/
void add_student();
int remove_student();
void view_students ();
void deleteAll ();
void printNode(struct s_student* node);
void getNth();
void getLength_i();
int getCount();
void getLength_r();
void getLastNthNode();
void findNthNodeFromEnd();
void getMiddle();
void reverse();

#endif /* LINKEDLIST_H_ */
