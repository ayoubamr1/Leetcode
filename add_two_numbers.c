#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
struct ListNode *createnode(int val)
{
	struct ListNode *node = malloc (sizeof(struct ListNode));
	node->val = val;
	node->next = NULL;
	return (node);
}
*/


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *Head = malloc (sizeof(struct ListNode));
	Head->val = 0;
	Head->next = NULL;
	struct ListNode *curr = Head;
	int reserve = 0;
	while (l1 || l2 || reserve)
	{
		int sum = reserve;
		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		reserve = sum / 10;
		curr->next = malloc (sizeof(struct ListNode));
		curr->next->val = sum % 10;
		curr->next->next = NULL;
		curr = curr->next;
	}
	return(Head->next);
}

/**
void	print_list(struct ListNode *head)
{
	struct ListNode *curr = head;
	while (curr)
	{
		printf("[%d]", curr->val);
		if (curr->next)
			printf(" -> ");
		curr = curr->next;
	}
	printf("\n");
}

int main ()
{
	struct ListNode *l1 = createnode(9);
	l1->next = createnode(8);
	l1->next->next = createnode(9);
	l1->next->next->next = createnode(9);
	l1->next->next->next->next = createnode(9);
	l1->next->next->next->next->next = createnode(9);

	struct ListNode* l2 = createnode(8);
	l2->next = createnode(8);
	l2->next->next = createnode(4);

	print_list(l1);
	print_list(l2);
	struct ListNode *sum = addTwoNumbers(l1, l2);
	print_list(sum);
}
*/