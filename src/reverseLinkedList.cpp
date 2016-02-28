/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *tmp = NULL, *prev = NULL,*prev1=NULL;
	
	prev = head;

	for (prev1 = tmp = head; tmp != NULL;)
	{


		if (tmp == head)
		{

			prev1 = tmp;
			tmp = tmp->next;
			prev1->next = NULL;
			head = prev1;
		}
		else if (tmp != NULL)
		{

			prev1 = tmp;
			tmp = tmp->next;
			prev1->next = head;
			head = prev1;
		}
		else
			tmp = tmp->next;

	}
	return head;
}
