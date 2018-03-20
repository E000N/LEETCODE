#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* SumList(struct ListNode* l1, struct ListNode* l2, int up, int empty)
{
    int upn = 0, num1 = 0, num2 = 0;
    struct ListNode *head;

    head = (struct ListNode*) malloc(sizeof(struct ListNode));

    if ( 1 == empty )
    {
        num1 = 0;
        num2 = l2->val;
        head->val = (num2 + up) % 10;
        if ((num2 + up) > 9)
        {
            upn = (l2->val + up) / 10;
        }
        if (l2->next == NULL)
        {
            if ( upn > 0 )
            {
                head->next = SumList(l1, l2, upn, 3);
                return head;
            }
            head->next = NULL;
            return head;
        }

        head->next = SumList(l1, l2->next, upn, 1);

        return head;
    }

    if ( 2 == empty )
    {
        num1 = l1->val;
        num2 = 0;
        head->val = (num1 + up) % 10;
        if ((num1 + up) > 9)
        {
            upn = (num1 + up) / 10;
        }
        if (l1->next == NULL)
        {
            if ( upn > 0 )
            {
                head->next = SumList(l1, l2, upn, 3);
                return head;
            }
            head->next = NULL;
            return head;
        }

        head->next = SumList(l1->next, l2, upn, 2);

        return head;
    }

    if ( 0 == empty )
    {
        num1 = l1->val;
        num2 = l2->val;
        head->val = (num1 + num2 + up) % 10;
        if ((num1 + num2 + up) > 9)
        {
            upn = (num1 + num2 + up) / 10;
        }

        if ( l1->next == NULL )
        {
            if ( l2->next == NULL )
            {
                if ( upn > 0 )
                {
                    head->next = SumList(l1, l2, upn, 3);
                    return head;
                }
                head->next = NULL;
                return head;
            }
            else
            {
                head->next = SumList(l1, l2->next, upn, 1);
                return head;
            }
        }
        else
        {
            if ( l2->next == NULL )
            {
                head->next = SumList(l1->next, l2, upn, 2);
                return head;
            }
            else
            {
                head->next = SumList(l1->next, l2->next, upn, 0);
                return head;
            }
        }

    }

    if ( 3 == empty )
    {
        head->val = up;
        head->next = NULL;
        return head;
    }

    return head;

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head;

    head = SumList(l1, l2, 0, 0);

    return head;
};

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

    ans = 0;

    p = addTwoNumbers(head1, head2);
    ans = p->val;
    while (p->next != NULL)
    {
        p = p->next;
        ans = ans + p->val;
    }

    printf("ans:%d", ans);

    return 0;
}

