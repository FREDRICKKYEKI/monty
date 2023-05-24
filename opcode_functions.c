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

/**
 * pint - prints the value at the top of the stack
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
*/
void pint(stack_t **head, unsigned int line_num)
{
	(void)line_num;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "can't pint, stack empty\n");
		free_globl();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * pop - pops the stack
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
*/
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	if(head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = (*head)->next;
	free(h);
}

/**
 * swap - swaps the top two elements in the stack
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
*/
void swap(stack_t **head, unsigned int line_num)
{
	int i = 0;
	stack_t *h = NULL;

	h = *head;

	for (; h != NULL; h = h->next, i++)
		;

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = (*head)->next;
	h->next = (*head)->next;
	h->prev = *head;
	(*head)->next = h;
	(*head)->prev = NULL;

}
