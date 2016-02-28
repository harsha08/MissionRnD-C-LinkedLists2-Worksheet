/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * insert_node(struct node *head,int k)
{
	struct node *ptr = NULL, *tmp = NULL,*prev=NULL;
	if (k<head->num)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->num = k;
		ptr->next = head;
		head = ptr;
	}
	else
	{
		prev = head;
		for (tmp = head; tmp != NULL; tmp = tmp->next){
			if (tmp->num >= k){
				break;
			}
			prev = tmp;
		}
		if (prev == head)
		{
			ptr = (struct node *)malloc(sizeof(struct node));
			ptr->num = k;

			ptr->next = head->next;
			head->next = ptr;
		}
		else
		{
			ptr = (struct node *)malloc(sizeof(struct node));
			ptr->num = k;
			prev->next = ptr;
			ptr->next = tmp;
		}
	}
	return head;
}


struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *tmp = head2;
	if (head1 == NULL && head2 == NULL)
	{
		return NULL;
	}
	else if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	for (; tmp != NULL; tmp = tmp->next)
	{
		head1=insert_node(head1, tmp->num);
	}
	return head1;
}
