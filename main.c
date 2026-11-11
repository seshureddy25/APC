/*
DOCUMENTATION:

NAME       : VEERAMREDDIGARI SESHU KUMAR REDDY
ADMIN ID   : 2601_108
START DATE : 07-10-2026
END DATE   : 30-10-2026

ARBITRARY PRECISION CALCULATOR (APC):

Developed a C-based Arbitrary Precision Calculator (APC) as part of the Data Structures and Algorithms (DSA) module. The application performs arithmetic 
operations on large integers beyond the range of standard C data types. It uses Singly Linked Lists to store and process large numbers digit by digit. It 
supports addition, subtraction, multiplication, and division, including positive and negative operands.The project demonstrates practical implementation 
of data structures, dynamic memory allocation, pointers, arithmetic operations.

KEY FEATURES:
* Performs arithmetic operations on large integers.
* Supports Addition, Subtraction, Multiplication, and Division.
* Handles positive and negative numbers.
* Uses Singly Linked Lists to represent large numbers digit by digit.
* Supports numbers with leading zeros.
* Validates command-line arguments and input operands.
* Handles invalid operators and invalid input characters.
* Includes division-by-zero validation.
* Displays the calculated result with the appropriate sign.

DATA STRUCTURES USED:

* Singly Linked List – Stores large numbers digit by digit using dynamically allocated nodes.
* Node – Stores an individual digit and a pointer to the next node.
* Result List – Stores the result of arithmetic operations dynamically.

TECHNOLOGIES USED:

C | Singly Linked Lists | Data Structures and Algorithms | Dynamic Memory Allocation | Pointers | Arithmetic Algorithms | String Manipulation | Command-Line Arguments

USAGE:

ERROR:
./APC.out : Invalid arguments

usage:

To perform addition:
./APC.out 123456789 + 987654321

To perform subtraction:
./APC.out 987654321 - 123456789

To perform multiplication:
./APC.out 123456789 x 987654321

To perform division:
./APC.out 987654321 / 123456789

To perform operations with negative numbers:
./APC.out -12345 + 6789

To perform operations with leading zeros:
./APC.out 000123 + 000456

SAMPLE OUTPUT:

$ ./APC.out 123456789 + 987654321

Result: +1111111110

$ ./APC.out 987654321 - 123456789

Result: +864197532

$ ./APC.out 123456789 x 2

Result: +246913578

$ ./APC.out 987654321 / 123

Result: +8029262

ERROR HANDLING:

* Displays an error message when command-line arguments are missing.
* Rejects operands containing invalid characters.
* Rejects operands containing only a sign without digits.
* Rejects unsupported arithmetic operators.
* Prevents division by zero.
*/


#include "common.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("USAGE:\n");
        printf("INFO : ./a.out  [operand(number)] [operator] [operand(number)]\n");
        printf("operator : + Addition\n");
        printf("           - Substraction\n");
        printf("           X Multiplication\n");
        printf("           / Division\n");
        return 0;
    }

    Node1 *tail1 = NULL;
    Node1 *head1 = NULL;
    Node2 *tail2 = NULL;
    Node2 *head2 = NULL;
    Result *tail_R = NULL;
    Result *head_R = NULL;

    int i=0;
    int found=0;
    if(argv[1][i]=='-' ||argv[1][i]=='+')
    {
        found=1;
        i++;
    }
    if(argv[1][i]=='x'||argv[1][i]=='/')
    {
        printf("INFO : Leading operators must be + or - or nothing is allowed\n");
        return 0;
    }
    while (argv[1][i] != '\0')
    {
        if (!isdigit((unsigned char)argv[1][i]))
        {
            printf("INFO : Numbers only allowed\n");
            return 0;
        }

        Node1 *newnode = malloc(sizeof(Node1));
        if (newnode == NULL)
        {
            printf("INFO : Memory allocation failed\n");
            return 0;
        }

        newnode->data = argv[1][i] - '0';
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head1 == NULL)
        {
            head1 = newnode;
            tail1 = newnode;
        }
        else
        {
            tail1->next = newnode;
            newnode->prev = tail1;
            tail1 = newnode;
        }
        i++;
    }
    i = 0;
    int found2=0;
    if(argv[3][i]=='-' ||argv[3][i]=='+')
    {
        i++;
        found2=1;
    }
    if(argv[3][i]=='x'||argv[3][i]=='/')
    {
        printf("INFO : Leading operators must be + or - or nothing is allowed\n");
        return 0;
    }
    while (argv[3][i] != '\0')
    {
        if (!isdigit((unsigned char)argv[3][i]))
        {
            printf("INFO : Numbers only allowed\n");
            return 0;
        }

        Node2 *newnode = malloc(sizeof(Node2));
        if (newnode == NULL)
        {
            printf("INFO : Memory allocation failed\n");
            return 0;
        }

        newnode->data = argv[3][i] - '0';
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head2 == NULL)
        {
            head2 = newnode;
            tail2 = newnode;
        }
        else
        {
            tail2->next = newnode;
            newnode->prev = tail2;
            tail2 = newnode;
        }
        i++;
    }

    if (head1 == NULL || head2 == NULL)
    {
        printf("INFO : Operands must not be empty\n");
        return 0;
    }

    trim_input_zeros(&head1, &tail1);
    trim_input_zeros(&head2, &tail2);
    if (head1 == NULL)
    {
        printf("INFO : First operand must contain digits\n");
        return 0;
    }

    if (head2 == NULL)
    {
        printf("INFO : Second operand must contain digits\n");
        return 0;
    }

    if (argv[2][0] == '\0' || argv[2][1] != '\0' || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '/' && argv[2][0] != 'X' && argv[2][0] != 'x'))
    {
        printf("INFO : Operator must be +, -, /, or X\n");
        return 0;
    }

    char sign1 = '+';
    char sign2 = '+';
    char operator = argv[2][0];

    if (found == 1)
        sign1 = argv[1][0];

    if (found2 == 1)
        sign2 = argv[3][0];

    char result_sign = '+';
    char effective_sign2 = sign2;
    if (operator == '-')
    {
        if (effective_sign2 == '+')
            effective_sign2 = '-';
        else
            effective_sign2 = '+';
    }

    switch (operator)
    {
        case '+':
        case '-':
            if (sign1 == effective_sign2)
            {
                result_sign = sign1;
                if (Addition(tail1, tail2, &head_R, &tail_R) != NULL)
                {
                    printf("%c", result_sign);
                    print_result(head_R);
                }
            }
            else
            {
                switch (compare(head1, head2))
                {
                    case GREATER_THAN:
                        result_sign = sign1;
                        if (Subtraction(tail1, tail2, &head_R, &tail_R) != NULL)
                        {
                            printf("%c", result_sign);
                            print_result(head_R);
                        }
                        break;

                    case LESS_THAN:
                        result_sign = effective_sign2;
                        if (Subtraction(tail2, tail1, &head_R, &tail_R) != NULL)
                        {
                            printf("%c", result_sign);
                            print_result(head_R);
                        }
                        break;
                    case EQUAL_TO:
                        result_sign = '+';

                        if (Subtraction(tail1, tail2, &head_R, &tail_R) != NULL)
                        {
                            printf("%c", result_sign);
                            print_result(head_R);
                        }
                        break;
                }
            }
            break;
        case 'X':
        case 'x':
            result_sign = (sign1 == sign2) ? '+' : '-';

            if (multiplication(tail1, tail2, &head_R, &tail_R) != NULL)
            {
                if (head_R->next == NULL && head_R->data == 0)
                    result_sign = '+';

                printf("%c", result_sign);
                print_result(head_R);
            }
        case '/':
            result_sign = (sign1 == sign2) ? '+' : '-';

            if (division(head1, head2, tail2, &head_R, &tail_R) != NULL)
            {
                printf("%c", result_sign);
                print_result(head_R);
            }
            break;

        default:
            printf("INFO : Invalid operation\n");
            break;
    }

    return 0;
}
