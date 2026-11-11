#include"common.h"

Result *Subtraction(Node1 *tail1, Node2 *tail2,Result **headR, Result **tailR)
{
    int borrow = 0;
    *headR = NULL;
    *tailR = NULL;
    while (tail1 != NULL || tail2 != NULL)
    {
        int left = (tail1 != NULL) ? tail1->data : 0;
        int right = (tail2 != NULL) ? tail2->data : 0;
        int digit = left - right - borrow;
        if (digit < 0)
        {
            digit += 10;
            borrow = 1;

        }
        else
        {
            borrow = 0;
        }

        add_result_node(headR, tailR, digit);
        if (*headR == NULL)
            return NULL;
        if (tail1 != NULL)
            tail1 = tail1->prev;

        if (tail2 != NULL)
            tail2 = tail2->prev;
    }
    trim_zeros(headR, tailR);
    if (*headR == NULL)
    {
        Result *newnode = malloc(sizeof(*newnode));

        if (newnode == NULL)
            return NULL;
        newnode->data = 0;
        newnode->prev = NULL;
        newnode->next = NULL;

        *headR = newnode;
        *tailR = newnode;
    }

    return *headR;
}
