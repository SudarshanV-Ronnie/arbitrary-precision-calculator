#include "apc.h"

/* ---------------------------------------------------------
   Function : insert_first
   Description : Inserts a new node at the beginning of the doubly linked list
----------------------------------------------------------*/
int insert_first(node **head, node **tail, int data)
{
    /* Allocate memory for new node */
    node *new = malloc(sizeof(node));

    /* Check if memory allocation failed */
    if(new == NULL)
    {
        return FAILURE;
    }

    /* Initialize node values */
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    /* Case 1 : List is empty */
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        /* Case 2 : Insert before existing head */
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return SUCCESS;
    }
}


/* ---------------------------------------------------------
   Function : insert_last
   Description : Inserts a new node at the end of the doubly linked list
----------------------------------------------------------*/
int insert_last(node **head, node **tail, int data)
{
    /* Allocate memory for new node */
    node *new = malloc(sizeof(node));

    /* Check if allocation failed */
    if(new == NULL)
    {
        return FAILURE;
    }

    /* Initialize node */
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    
    /* Case 1 : List is empty */
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        /* Case 2 : Insert after current tail */
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
        return SUCCESS;
    }
}


/* ---------------------------------------------------------
   Function : compare_list
   Description : Compares two numbers stored in linked lists
    Returns:
             1  -> list1 > list2
            -1  -> list1 < list2
             0  -> list1 == list2
----------------------------------------------------------*/
int compare_list(node *head1, node *head2)
{
    int len1 = 0, len2 = 0;

    node *temp1 = head1;
    node *temp2 = head2;

    /* Calculate length of first list */
    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    /* Calculate length of second list */
    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    /* If lengths are different, larger length means larger number */
    if (len1 > len2)
        return 1;
    else if (len1 < len2)
        return -1;

    /* If lengths are equal, compare digit by digit */
    temp1 = head1;
    temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data)
            return 1;
        else if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    /* Numbers are equal */
    return 0; 
}


/* ---------------------------------------------------------
   Function : print_list
   Description : Prints the digits stored in linked list
----------------------------------------------------------*/
void print_list(node *head)
{
    /* Check if list is empty */
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* Traverse list and print each digit */
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}