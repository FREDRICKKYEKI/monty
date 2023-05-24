#include "monty.h"
/**
 * push - pushes element to stack
 *
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 *
 * Return: void
*/
void push(stack_t **head, unsigned int line_num)
{
	int n, i;

	if (!globl_vars.arg)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		free_globl();
		exit(EXIT_FAILURE);
	}

	for (i = 0; globl_vars.arg[i] != '\0'; i++)
	{
		if (!isdigit(globl_vars.arg[i]) && globl_vars.arg[i] != '-')
		{
			dprintf(2, "L%u: ", line_num);
			dprintf(2, "usage: push integer\n");
			free_globl();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(globl_vars.arg);

	if (globl_vars.st_q == 1)
		add_dnodeint(head, n);
	else
		add_dnodeint_end(head, n);
}

/**
 * pall - prints all the values stored in the stack
 *
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
*/
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
