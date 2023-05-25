#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void mod(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}

	h = (*head)->next;
	h->n %= (*head)->n;
	pop(head, line_num);
}
