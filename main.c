/* Name: Sudarshan V
   Date: 09-04-2026
   Description: APC (Arbitrary Precision Calculator)
   Performs +, -, x, / operations using linked lists
*/

#include "apc.h"
#include <ctype.h>

/* ---------------------------------------------------------
   Function : validate
   Description : Validates command line arguments
   Checks:
   1. Correct number of arguments
   2. Valid operator
   3. Operands contain only digits
----------------------------------------------------------*/
int validate(int argc, char *argv[])
{
    /* Check if correct number of arguments are passed */
    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return 0;
    }

    /* Validate operator */
    if (!(argv[2][0] == '+' || argv[2][0] == '-' ||
          argv[2][0] == 'x' || argv[2][0] == 'X' ||
          argv[2][0] == '/'))
    {
        printf("Error: Invalid operator\n");
        return 0;
    }

    int i = 0;

    /* -------- Validate operand1 -------- */

    /* Skip sign if present */
    if (argv[1][0] == '+' || argv[1][0] == '-')
        i = 1;

    /* Check each character is a digit */
    while(argv[1][i] != '\0')
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Error: Operand1 must be a number\n");
            return 0;
        }
        i++;
    }

    /* -------- Validate operand2 -------- */

    i = 0;

    /* Skip sign if present */
    if (argv[3][0] == '+' || argv[3][0] == '-')
        i = 1;

    /* Check each character is a digit */
    while(argv[3][i] != '\0')
    {
        if (!isdigit(argv[3][i]))
        {
            printf("Error: Operand2 must be a number\n");
            return 0;
        }
        i++;
    }

    return 1;   // validation successful
}


/* ---------------------------------------------------------
   Function : create_list
   Description : Converts operand string into linked list
   Example : "1234" → 1 → 2 → 3 → 4
----------------------------------------------------------*/
void create_list(char *opr, node **head, node **tail)
{
    int i = 0;

    /* Skip sign character if present */
    if (opr[0] == '+' || opr[0] == '-')
        i = 1;

    /* Convert each digit into node */
    for (; opr[i] != '\0'; i++)
    {
        int digit = opr[i] - '0';      // convert char to integer
        insert_last(head, tail, digit); // insert digit into list
    }
}


/* ---------------------------------------------------------
   MAIN FUNCTION
   Controls the overall calculator operation
----------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* Linked list pointers for operands and result */
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

    /* Validate command line arguments */
    if (!validate(argc, argv))
        return 0;

    /* Detect sign of operands */
    int sign1 = 1, sign2 = 1;

    if (argv[1][0] == '-')
        sign1 = -1;

    if (argv[3][0] == '-')
        sign2 = -1;

    /* Create linked lists from operands */
    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    /* Store operator */
    char oper = argv[2][0];

    /* Perform operation based on operator */
    switch (oper)
    {
        /* ---------------- ADDITION ---------------- */
        case '+':
        {
            /* If both operands have same sign */
            if (sign1 == sign2)
            {
                addition(tail1, tail2, &headR, &tailR);

                /* If numbers are negative, print '-' */
                if (sign1 == -1)
                    printf("-");
            }
            else
            {
                /* Compare magnitude of numbers */
                int cmp = compare_list(head1, head2);

                if (cmp >= 0)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    if (sign1 == -1)
                        printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    if (sign2 == -1)
                        printf("-");
                }
            }

            /* Print result */
            print_list(headR);
            printf("\n");
            break;
        }

        /* ---------------- SUBTRACTION ---------------- */
        case '-':
        {
            int cmp = compare_list(head1, head2);

            if (cmp >= 0)
            {
                subtraction(tail1, tail2, &headR, &tailR);
            }
            else
            {
                subtraction(tail2, tail1, &headR, &tailR);
                printf("-");   // result is negative
            }

            print_list(headR);
            printf("\n");
            break;
        }

        /* ---------------- MULTIPLICATION ---------------- */
        case 'x':
        case 'X':
        {
            multiplication(tail1, tail2, &headR, &tailR);

            /* Result sign depends on operand signs */
            if (sign1 != sign2)
                printf("-");

            printf("Result: ");
            print_list(headR);
            printf("\n");
            break;
        }

        /* ---------------- DIVISION ---------------- */
        case '/':
        {
            /* Check division by zero */
            if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
            {
                printf("Error: Division by zero\n");
                break;
            }

            division(head1, head2, &headR, &tailR);

            /* Result sign logic */
            if (sign1 != sign2)
                printf("-");

            print_list(headR);
            printf("\n");
            break;
        }

        /* Invalid operator case */
        default:
            printf("Invalid operator\n");
    }

    return 0;
}