#include "apc.h"

/* ---------------------------------------------------------
   Function : subtraction
   Description : Subtracts two large numbers stored in linked lists digit by digit.
   The subtraction starts from the last digit (like manual subtraction).
----------------------------------------------------------*/
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    /* temp pointers start from the last digit */
    node *temp1 = tail1;
    node *temp2 = tail2;

    int diff, borrow = 0;   // borrow is used when result becomes negative

    /* Continue until both lists are completely processed */
    while (temp1 != NULL || temp2 != NULL)
    {
        /* Case 1: Both digits are present */
        if (temp1 != NULL && temp2 != NULL)
        {
            diff = temp1->data - temp2->data - borrow;
        }

        /* Case 2: Only first number has digits */
        else if (temp1 != NULL)
        {
            diff = temp1->data - borrow;
        }

        /* Case 3: Only second number has digits */
        else
        {
            diff = 0 - temp2->data - borrow;
        }

        /* If result becomes negative, borrow from next digit */
        if (diff < 0)
        {
            diff = diff + 10;   // adjust digit after borrow
            borrow = 1;         // set borrow for next subtraction
        }
        else
        {
            borrow = 0;         // no borrow needed
        }

        /* Insert result digit at the beginning of result list */
        insert_first(headR, tailR, diff);

        /* Move to previous digit of first number */
        if (temp1 != NULL)
            temp1 = temp1->prev;

        /* Move to previous digit of second number */
        if (temp2 != NULL)
            temp2 = temp2->prev;
    }

    /* ---------------------------------------------------
       Remove leading zeros from result
       Example: 00045 → 45
    ---------------------------------------------------*/
    while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        node *temp = *headR;        // store current head
        *headR = (*headR)->next;    // move head to next node
        (*headR)->prev = NULL;      // update prev pointer
        free(temp);                 // free removed node
    }
}