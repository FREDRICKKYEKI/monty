#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 *
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
 */
void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *h1;
	stack_t *h2;
	(void)line_num;

	h1 = NULL;
	h2 = NULL;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	h1 = (*head)->next;
	h2 = *head;

	while (h2->next != NULL)
		h2 = h2->next;


	h1->prev = NULL;
	h2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = h2;
	*head = h1;
}

/**
 * rotr - rotates the stack to the bottom.
 *
 * @head: pointer to head of doubly linked list
 * @line_num: line number
 * Return: void
 */
void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *h = NULL;
	(void)line_num;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	h = *head;

	while (h->next != NULL)
		h = h->next;

	h->prev->next = NULL;
	h->next = *head;
	h->prev = NULL;
	(*head)->prev = h;
	*head = h;
}
