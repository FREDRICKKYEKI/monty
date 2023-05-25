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

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void pchar(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;

	while (h && h->n > 0 && h->n < 128)
	{
		printf("%c", h->n);
		h = h->next;
	}

	printf("\n");
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	globl_vars.st_q = 0;
}

/**
 * stack - sets the format fo the data to a stack (LIFO)
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	globl_vars.st_q = 1;
}
