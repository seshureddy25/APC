#include "common.h"

void add_result_node(Result **headR, Result **tailR, int data)
{
    Result *newnode = malloc(sizeof(*newnode));
    if (newnode == NULL)
    {
        printf("INFO : Failed to allocate memory\n");
        return;
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (*headR == NULL)
    {
        *headR = newnode;
        *tailR = newnode;
    }
    else
    {
        newnode->next = *headR;
        (*headR)->prev = newnode;
        *headR = newnode;
    }
}
void trim_zeros(Result **headR, Result **tailR)
{
    while (*headR != NULL && (*headR)->next != NULL && (*headR)->data == 0)
    {
        Result *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        if (*tailR == temp)
            *tailR = *headR;
        free(temp);
    }
    if (*headR == NULL)
        *tailR = NULL;
}

int compare(Node1 *head1, Node2 *head2)
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

void trim_input_zeros(Node1 **head, Node1 **tail)
{
    while (*head != NULL && *head != *tail && (*head)->data == 0)
    {
        Node1 *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
void print_result(Result *head)
{
    Result *current = head;
    if (current == NULL)
    {
        printf("INFO : Operation failed\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}
