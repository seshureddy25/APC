#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include <ctype.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node1, Node2,Result,Result1,Result2;

#define GREATER_THAN 1
#define LESS_THAN 0
#define EQUAL_TO 2

int compare(Node1 *, Node2 *);
void trim_input_zeros(Node1 **, Node1 **);
Result *Addition(Node1 *, Node2 *, Result **, Result **);
Result *Subtraction(Node1 *, Node2 *, Result **, Result **);
Result *multiplication(Node1 *tail1, Node2 *tail2, Result **headR, Result **tailR);
Result  *division(Node1 *head1, Node2 *head2, Node2 *tail2, Result **head_R, Result **tail_R);
void add_result_node(Result **headR, Result **tailR, int data);
void trim_zeros(Result **headR, Result **tailR);
int compare(Node1 *head1, Node2 *head2);
void print_result(Result *head);
