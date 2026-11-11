#include"common.h"

Result *Addition(Node1 *tail1, Node2 *tail2, Result **headR, Result **tailR)
{
    int result;
    int carry = 0;
    *headR = NULL;
    *tailR = NULL;
    while (tail1 != NULL || tail2 != NULL)
    {
        result = carry;
        if (tail2 != NULL)
        {
            result += tail2->data;
            tail2 = tail2->prev;
        }
        if (tail1 != NULL)
        {
            result += tail1->data;
            tail1 = tail1->prev;
        }
        carry = result / 10;
        result = result % 10;
        add_result_node(headR, tailR, result);
    }
    if (carry)
        add_result_node(headR, tailR, carry);

    return *headR;
}

