#include "monty.h"

/**
 * free_globl - frees the global variables
 *
 * Return: void
*/
void free_globl(void)
{
	free_dlistint(globl_vars.head);
	free(globl_vars.buff);
	fclose(globl_vars.file_desc);
}

/**
 * init_globl - initializes the global variables' values
 * @fd: file descriptor
 *
 * Return: void
*/
void init_globl(FILE *fd)
{
	globl_vars.st_q = 1;
	globl_vars.curr_line = 1;
	globl_vars.file_desc = fd;
	globl_vars.arg = NULL;
	globl_vars.head = NULL;
	globl_vars.buff = NULL;
}

/**
 * get_file_desc - gets file descriptor of file
 * passed as argument and checks if can be opened
 *
 * @argc: argument count
 * @argv: argument array/vector
 *
 * Return: file descriptor
*/
FILE *get_file_desc(int argc, char *argv[])
{
	FILE *fd;

	if (argc > 2 || argc == 1)
	{
		dprintf(2, "usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
