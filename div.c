#include "apc.h"

/* ---------------------------------------------------------
   Function : division
   Description : Divides two large numbers stored in linked lists using repeated subtraction method.
   Result (quotient) is stored in result list.
----------------------------------------------------------*/
void division(node *head1, node *head2, node **headR, node **tailR)
{
    node *dividend = head1;   // dividend starts as the first number
    int count = 0;            // count how many times subtraction occurs

    /* Repeat subtraction while dividend >= divisor */
    while (compare_list(dividend, head2) >= 0)
    {
        node *resH = NULL;    // temporary result head
        node *resT = NULL;    // temporary result tail

        /* Find tail of current dividend */
        node *tail1 = dividend;
        while (tail1->next)
            tail1 = tail1->next;

        /* Find tail of divisor */
        node *tail2 = head2;
        while (tail2->next)
            tail2 = tail2->next;

        /* Subtract divisor from dividend */
        subtraction(tail1, tail2, &resH, &resT);

        /* Update dividend with new result */
        dividend = resH;

        /* Increase quotient count */
        count++;
    }

    /* If divisor is larger than dividend → quotient = 0 */
    if (count == 0)
    {
        insert_last(headR, tailR, 0);
        return;
    }

    /* Convert quotient count into linked list digits */
    while (count > 0)
    {
        insert_first(headR, tailR, count % 10);  // store last digit
        count = count / 10;                      // remove last digit
    }
}