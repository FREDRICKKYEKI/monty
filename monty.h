#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct globl_s - global struct to use in functions
 * @st_q: is stack or queue
 * @curr_line: current line
 * @arg: second argument inside the current line
 * @head: head of doubly linked list
 * @file_desc: file descriptor
 * @buff: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues project
 */
typedef struct globl_s
{
	int st_q;
	unsigned int curr_line;
	char *arg;
	stack_t *head;
	FILE *file_desc;
	char *buff;
} globl_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern globl_t globl_vars;

/*opcode functions*/
void push(stack_t **head, unsigned int line_num);
void pall(stack_t **head, unsigned int line_num);
void pint(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void swap(stack_t **head, unsigned int line_num);

void add(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);

void mod(stack_t **head, unsigned int line_num);
void pchar(stack_t **head, unsigned int line_num);
void pstr(stack_t **head, unsigned int line_num);
void queue(stack_t **head, unsigned int line_num);
void stack(stack_t **head, unsigned int line_num);

void rotr(stack_t **head, unsigned int line_num);
void rotl(stack_t **head, unsigned int line_num);

/*get operation codes function - get_opcodes*/
void (*get_opcode_func(char *op_code))(stack_t **stack, unsigned int line_num);

/*doubly linked list functions - doub_functions*/
void free_dlistint(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/*main functions - main_functions*/
void free_globl(void);
void init_globl(FILE *fd);
FILE *get_file_desc(int argc, char *argv[]);

/*string functions - string_functions*/
int _strcmp(char *s1, char *s2);

#endif
