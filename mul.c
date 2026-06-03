#include "apc.h"

/* ---------------------------------------------------------
   Function : multiplication
   Description : Multiplies two large numbers stored in linked lists using the same method as manual multiplication.
----------------------------------------------------------*/
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *ptr2 = tail2;   // pointer to traverse second number
    int shift = 0;        // used to add zeros (place value shift)

    /* Initialize result list as empty */
    *headR = NULL;
    *tailR = NULL;

    /* Traverse second number from last digit to first */
    while (ptr2 != NULL)
    {
        node *ptr1 = tail1;   // pointer to traverse first number
        node *tempH = NULL;   // temporary result head
        node *tempT = NULL;   // temporary result tail
        int carry = 0;

        /* Multiply current digit of number2 with all digits of number1 */
        while (ptr1 != NULL)
        {
            /* Multiply digits and add carry */
            int prod = (ptr1->data * ptr2->data) + carry;

            int digit = prod % 10;  // store single digit
            carry = prod / 10;      // update carry

            /* Insert result digit at beginning of temp list */
            insert_first(&tempH, &tempT, digit);

            /* Move to previous digit of first number */
            ptr1 = ptr1->prev;
        }

        /* If carry remains after finishing multiplication */
        if (carry)
        {
            insert_first(&tempH, &tempT, carry);
        }

        /* --------------------------------------------
           Add zeros at the end for place value shift
           Example:
           123 × 4  → 492
           123 × 5  → 6150 (one shift)
        ---------------------------------------------*/
        for (int i = 0; i < shift; i++)
        {
            insert_last(&tempH, &tempT, 0);
        }

        /* If this is the first multiplication result */
        if (*tailR == NULL)
        {
            *headR = tempH;
            *tailR = tempT;
        }
        else
        {
            /* Add the new temporary result with previous result */

            node *oldHead = *headR;
            node *oldTail = *tailR;

            /* Reset result list to store new addition result */
            *headR = NULL;
            *tailR = NULL;

            addition(oldTail, tempT, headR, tailR);
        }

        /* Increase shift for next digit multiplication */
        shift++;

        /* Move to next digit of second number */
        ptr2 = ptr2->prev;
    }
}