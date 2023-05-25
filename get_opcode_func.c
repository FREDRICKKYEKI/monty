#include "monty.h"
/**
 * get_opcode_func - gets funtion based on user input
 *
 * @op_code: code passed from input
 *
 * Return: pointer to the corresponding function
*/
void (*get_opcode_func(char *op_code))(stack_t **stack, unsigned int line_num)
{
	int i;
	instruction_t opcode[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{NULL, NULL},
	};

	for (i = 0; opcode[i].opcode; i++)
	{
		if (_strcmp(opcode[i].opcode, op_code) == 0)
			break;
	}

	return (opcode[i].f);
}
