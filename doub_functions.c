#include "monty.h"
/**
 * free_dlistint - frees a stack_t list
 * @head: head of list
 *
 * Return: void
*/
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}

/**
 * add_dnodeint - adds a new list at the beginning
 * of a new list
 * @head: pointer to pointer of head of list
 * @n: integer to store in the list
 *
 * Return: address of new element or NULL if it fails
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *h;
	stack_t *new_head;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globl();
		exit(EXIT_FAILURE);
	}

	new_head->n = n;
	new_head->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	new_head->next = h;

	if (h != NULL)
		h->prev = new_head;

	*head = new_head;

	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at the
 * end of a stack_t list.
 * @head: pointer to pointer to head of list.
 * @n: int to be stored.
 *
 * Return: address of new element.
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *h;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globl();
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = h;

	return (h->next);
}
