/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void insert(struct node *ptr, struct node *ptr1, int k)
{
	struct node *tmp = NULL,*newnode=NULL;
	tmp = ptr->next;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->num = k;
	newnode->next = ptr1;
	ptr->next = newnode;
	
}
struct node * insertAtEveryKthNode(struct node *head, int K) {
	int count = 1;
	struct node *tmp, *prev;
	tmp = prev = head;
	while (tmp != NULL)
	{
		if (count%K == 0)
		{
			prev = tmp;
			tmp = tmp->next;
			insert(prev,tmp, K);
		}
		else
			tmp = tmp->next;
		count++;
	}
	return head;
}
