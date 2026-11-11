#include"common.h"
int insert_last(Result1 **head, Result1 **tail , Node1 **temp)
{
    Result1 *newnode = malloc(sizeof(*newnode));
    if(temp==NULL)
    {
        return 0;
    }
    if (newnode == NULL)
    {
        printf("INFO : Failed to allocate memory\n");
        return 0;
    }
    newnode->data =(*temp)->data;
    newnode->next = NULL;
    newnode->prev = *tail;
    if (*tail != NULL)
        (*tail)->next = newnode;
    else
        *head = newnode;
    *tail = newnode;
    *temp=(*temp)->next;
    return 1;
}
int insert_data_end(Result **head, Result **tail,int data)
{
    Result2 *newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
    {
        printf("INFO : Failed to allocate memory\n");
        return 0;
    }

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = *tail;

    if (*tail != NULL)
        (*tail)->next = newnode;
    else
        *head = newnode;
    *tail = newnode;
    return 1;
}
int compare1(Result1 *head1, Node2 *head2)
{
    int count1 = 0;
    int count2 = 0;
    Node1 *temp1 = head1;
    Node2 *temp2 = head2;
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }
    if (count1 < count2)
        return LESS_THAN;
    if (count1 > count2)
        return GREATER_THAN;
    temp1 = head1;
    temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
            return LESS_THAN;
        if (temp1->data > temp2->data)
            return GREATER_THAN;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return EQUAL_TO;
}
Result *division(Node1 *head1, Node2 *head2,Node2 *tail2, Result **head_R, Result **tail_R)
{
    if (head1 == NULL || head2 == NULL)
    {
        printf("INFO : List is empty\n");
        return NULL;
    }
    *head_R = NULL;
    *tail_R = NULL;
    Node2 *temp = head2;
    while (temp != NULL && temp->data == 0)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("INFO : Division by zero\n");
        return NULL;
    }
    Node1 *temp1 = head1;
    Result *head_R1 = NULL;
    Result *tail_R1 = NULL;
    while (temp1 != NULL)
    {
        if (!insert_last(&head_R1, &tail_R1, &temp1))
            goto failure;
        trim_zeros(&head_R1, &tail_R1);
        int count = 0;
        while (compare1(head_R1, head2) != LESS_THAN)
        {
            Result *head_R2 = NULL;
            Result *tail_R2 = NULL;
            if (Subtraction(tail_R1, tail2, &head_R2, &tail_R2) == NULL)
                goto failure;
            while (head_R1 != NULL)
            {
                Result *node = head_R1;
                head_R1 = head_R1->next;
                free(node);
            }
            head_R1 = head_R2;
            tail_R1 = tail_R2;
            trim_zeros(&head_R1, &tail_R1);
            count++;
        }
        if (!insert_data_end(head_R, tail_R, count))
            goto failure;
    }
    trim_zeros(head_R, tail_R);
    while (head_R1 != NULL)
    {
        Result *node = head_R1;
        head_R1 = head_R1->next;
        free(node);
    }
    return *head_R;
failure:
    while (head_R1 != NULL)
    {
        Result *node = head_R1;
        head_R1 = head_R1->next;
        free(node);
    }
    while (*head_R != NULL)
    {
        Result *node = *head_R;
        *head_R = (*head_R)->next;
        free(node);
    }
    *tail_R = NULL;
    return NULL;
}