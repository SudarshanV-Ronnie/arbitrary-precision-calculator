#include "apc.h"

/* ---------------------------------------------------------
   Function : addition
   Description : Adds two large numbers stored in linked lists Digit-by-digit from right to left.
    Result is stored in another linked list.
----------------------------------------------------------*/
void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    /* Start from the last digit of both numbers */
    node *temp1 = tail1;
    node *temp2 = tail2;

    int sum, carry = 0;   // carry is used when sum exceeds 9

    /* Continue until both lists are finished and carry becomes 0 */
    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int val1 = 0, val2 = 0;   // store current digits

        /* Get digit from first number */
        if (temp1 != NULL)
        {
            val1 = temp1->data;   // read digit
            temp1 = temp1->prev;  // move to previous digit
        }

        /* Get digit from second number */
        if (temp2 != NULL)
        {
            val2 = temp2->data;   // read digit
            temp2 = temp2->prev;  // move to previous digit
        }

        /* Add digits along with carry */
        sum = val1 + val2 + carry;

        /* Calculate new carry */
        carry = sum / 10;     

        /* Store the single digit result */
        sum = sum % 10;       

        /* Insert result digit at beginning of result list */
        insert_first(headR, tailR, sum);
    }
}