#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @head: pointer to head of head linked list
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

/**
 * nop - doesn't do anything
 * @head: pointer to head of head linked list
 * @line_num: line number
 * Return: void
*/
void nop(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
}

/**
 * sub - subtracts the top two elements of the stack
 * @head: pointer to head of head linked list
 * @line_num: line number
 * Return: void
*/
void sub(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}

	h = (*head)->next;
	h->n -= (*head)->n;
	pop(head, line_num);
}

/**
 * _div - divides the second top element of the stack by the
 * top element of the stack.
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _div(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
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
	h->n /= (*head)->n;
	pop(head, line_num);
}

/**
 * mul - multiplies the second top element of the stack by the
 * top element of the stack.
 *
 * @head: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void mul(stack_t **head, unsigned int line_num)
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
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_globl();
		exit(EXIT_FAILURE);
	}

	h = (*head)->next;
	h->n *= (*head)->n;
	pop(head, line_num);
}
