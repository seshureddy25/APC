#include "common.h"

int insert_front(Result2 **head, Result2 **tail, int digit)
{
    Result2 *newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
    {
        printf("INFO : Failed to allocate memory\n");
        return 0;
    }
    newnode->data = digit;
    newnode->prev = NULL;
    newnode->next = *head;

    if (*head != NULL)
        (*head)->prev = newnode;
    else
        *tail = newnode;
    *head = newnode;
    return 1;
}
int insert_zero_end(Result2 **head, Result2 **tail)
{
    Result2 *newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
    {
        printf("INFO : Failed to allocate memory\n");
        return 0;
    }

    newnode->data = 0;
    newnode->next = NULL;
    newnode->prev = *tail;

    if (*tail != NULL)
        (*tail)->next = newnode;
    else
        *head = newnode;
    *tail = newnode;
    return 1;
}

void free_result2(Result2 *head)
{
    while (head != NULL)
    {
        Result2 *temp = head;
        head = head->next;
        free(temp);
    }
}

void free_result1(Result1 *head)
{
    while (head != NULL)
    {
        Result1 *temp = head;
        head = head->next;
        free(temp);
    }
}

Result *multiplication(Node1 *tail1, Node2 *tail2, Result **head_R, Result **tail_R)
{
    *head_R = NULL;
    *tail_R = NULL;
    if (tail1 == NULL || tail2 == NULL)
    {
        printf("INFO : Given list is empty\n");
        return NULL;
    }
    Result1 *head_R1 = NULL;
    Result1 *tail_R1 = NULL;
    int count = 0;
    Node2 *temp2 = tail2;
    while (temp2 != NULL)
    {
        Result2 *head_R2 = NULL;
        Result2 *tail_R2 = NULL;
        Node1 *temp1 = tail1;
        int carry = 0;
        while (temp1 != NULL)
        {
            int result = temp1->data * temp2->data + carry;
            if (!insert_front(&head_R2, &tail_R2, result % 10))
            {
                free_result2(head_R2);
                free_result1(head_R1);
                return NULL;
            }
            carry = result / 10;
            temp1 = temp1->prev;
        }
        while (carry > 0)
        {
            if (!insert_front(&head_R2, &tail_R2, carry % 10))
            {
                free_result2(head_R2);
                free_result1(head_R1);
                return NULL;
            }
            carry /= 10;
        }
        for (int i = 0; i < count; i++)
        {
            if (!insert_zero_end(&head_R2, &tail_R2))
            {
                free_result2(head_R2);
                free_result1(head_R1);
                return NULL;
            }
        }
        if (head_R1 == NULL)
        {
            head_R1 = head_R2;
            tail_R1 = tail_R2;
            head_R2 = NULL;
            tail_R2 = NULL;
        }
        else
        {
            Result *head_R = NULL;
            Result *tail_R = NULL;
            if (Addition(tail_R1, tail_R2,&head_R, &tail_R) == NULL)
            {
                free_result2(head_R2);
                free_result1(head_R1);
                return NULL;
            }
            free_result1(head_R1);
            free_result2(head_R2);
            head_R1 = head_R;
            tail_R1 = tail_R;
        }

        temp2 = temp2->prev;
        count++;
    }
    trim_zeros(&head_R1, &tail_R1);
    *head_R = head_R1;
    *tail_R = tail_R1;
    return *head_R;
}
