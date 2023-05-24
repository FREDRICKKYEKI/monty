#include "monty.h"

globl_t globl_vars;

/**
 * main - entry point of the program
 * 
 * @argc: the argument count
 * @argv: the argument array/vector
 * 
 * Return: 0 if success	
*/
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_num);
	FILE *fd;
	int noflines = 0;
	size_t size = 256;
	char *line[2] = {NULL, NULL};

	fd = get_file_desc(argc, argv);
	init_globl(fd);
	noflines = getline(&globl_vars.buff, &size, fd);

	while (noflines != -1)
	{
		line[0] = strtok(globl_vars.buff, " \t\n");

		if (line[0] && line[0][0] != '#')
		{
			f = get_opcode_func(line[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globl_vars.curr_line);
				dprintf(2, "unknown instruction %s\n ", line[0]);
				free_globl();
				exit(EXIT_FAILURE);
			}
			globl_vars.arg = strtok(NULL, " \t\n");
			f(&globl_vars.head, globl_vars.curr_line);
		}
		noflines = getline(&globl_vars.buff, &size, fd);
		globl_vars.curr_line++;
	}
	free_globl();

	return (0);
}
