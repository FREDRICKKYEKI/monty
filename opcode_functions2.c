#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
*/
void add(stack_t **head, unsigned int line_num)
{
	int i = 0;
	stack_t *h = NULL;

	h = *head;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}

	h = (*head)->next;
	h->n += (*head)->n;
	pop(head, line_num);
}
