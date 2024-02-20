#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: double pointer to the head of the doubly linked list
 *
 * Description: This function implements the Insertion sort algorithm
 * to sort a doubly linked list of integers in ascending order. After each swap,
 * the current state of the list is printed.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current;
        while (temp->prev && temp->n < temp->prev->n)
        {
            /* Swap nodes */
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            if (temp->next->next)
                temp->next->next->prev = temp->next;

            print_list(*list); /* Function call to print the list */
        }
        current = current->next;
    }
}

