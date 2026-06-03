#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Status macros used by functions */
#define SUCCESS     1       // Operation completed successfully
#define FAILURE     0       // Operation failed

/* Macros used while comparing operands */
#define SAME        0       // Both operands are equal
#define OPERAND1    1       // Operand1 is greater
#define OPERAND2    2       // Operand2 is greater


/* Node structure for doubly linked list
   Each node stores one digit of a number */
typedef struct node
{
    struct node *prev;     // Pointer to previous node
    int data;              // Stores the digit
    struct node *next;     // Pointer to next node
} node;


/* Arithmetic operation functions */

void addition(node *tail1, node *tail2, node **headR, node **tailR);
/* Adds two large numbers stored as linked lists */

void subtraction(node *tail1, node *tail2, node **headR, node **tailR);
/* Subtracts second number from first number */

void multiplication(node *tail1, node *tail2, node **headR, node **tailR);
/* Multiplies two large numbers */

void division(node *head1, node *head2, node **headR, node **tailR);
/* Divides first number by second number */


/* Command line argument validation */
int cla_validation(int argc, char *argv[]);
/* Checks if operands and operator given in command line are valid */


/* Creates linked list from operand string */
void create_list(char *opr, node **head, node **tail);
/* Converts a number string into a doubly linked list */


/* Linked list helper functions */

int insert_first(node **head, node **tail, int data);
/* Inserts a node at the beginning of the list */

int insert_last(node **head, node **tail, int data);
/* Inserts a node at the end of the list */

int delete_list(node **head, node **tail);
/* Deletes entire linked list */

void print_list(node *head);
/* Prints the linked list number */


/* Utility functions */

int compare_list(node *head1, node *head2);
/* Compares two numbers stored in linked lists */

int list_len(node *head);
/* Returns the length (number of digits) of the list */

void remove_pre_zeros(node **head);
/* Removes leading zeros from the result list */


#endif