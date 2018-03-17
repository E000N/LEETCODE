#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
long long int SumList(struct ListNode* l1, int *len)
{
	long long int ans = 0;

	if (l1->next != NULL)
	{
		ans = SumList(l1->next, len);
	}

	ans = ans * 10 + l1->val;

	(*len)++;

	return ans;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	long long int sum = 0;
	long long int num1 = 0;
	long long int num2 = 0;
	int len = 0;
	int i = 0;

	int *pn;

	struct ListNode *p, *pl, *head;

	head = (struct ListNode*) malloc(sizeof(struct ListNode));

	num1 = SumList(l1, &i);

	len = i;
	i = 0;

	num2 = SumList(l2, &i);

	if (len < i)
	{
		len = i;
	}

	len = len + 1;

	printf("num1 %d num2 %d\n", num1, num2);

	sum = num1 + num2;
	pn = (int*)malloc(sizeof(int)*len);

	if (sum == 0)
	{
		head->val = 0;
		head->next = NULL;
		return head;
	}

	len = 0;
	while (sum != 0)
	{
		pn[len] = sum % 10;
		sum = sum / 10;
		len++;
	}

	p = head;
	i = 0;
	while (i < len)
	{
		p->val = pn[i];
		i++;
		if (i >= len)
		{
			p->next = NULL;
			break;
		}
		pl = (struct ListNode*) malloc(sizeof(struct ListNode));
		p->next = pl;
		p = pl;
	}
	pl->next = NULL;
	return head;
}

int main()
{
	int ans = 0;
	int i = 0;

	struct ListNode *p, *l1, *l2, *head1, *head2;

	head1 = (struct ListNode*) malloc(sizeof(struct ListNode));
	head1->val = 2;
	l1 = (struct ListNode*) malloc(sizeof(struct ListNode));
	head1->next = l1;
	l1->val = 4;
	p = (struct ListNode*) malloc(sizeof(struct ListNode));
	l1->next = p;
	p->val = 3;
	p->next = NULL;

	head2 = (struct ListNode*) malloc(sizeof(struct ListNode));
	head2->val = 5;
	l2 = (struct ListNode*) malloc(sizeof(struct ListNode));
	head2->next = l2;
	l2->val = 6;
	p = (struct ListNode*) malloc(sizeof(struct ListNode));
	l2->next = p;
	p->val = 4;
	p->next = NULL;

	ans = SumList(head1, &i);
	printf("num1 %d\n", ans);

	ans = SumList(head2, &i);
	printf("num2 %d\n", ans);

	ans = 0;

	p = addTwoNumbers(head1, head2);
	ans = p->val;
	while (p->next != NULL)
	{
		p = p->next;
		ans = ans * 10 + p->val;
	}

	printf("ans:%d", ans);

	return 0;
}

