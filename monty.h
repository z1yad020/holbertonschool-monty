#ifndef __FILE_NAME__
#define __FILE_NAME__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define DELIM " \n\t\r"

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
	void (*f)(stack_t **stack, size_t line_number);
} instruction_t;


extern instruction_t opcodes[8];
extern stack_t *top;


void execvecommand(stack_t **, char *, size_t);
int isint(char *);

void dispose(stack_t *);
void push(stack_t **, size_t);
void pall(stack_t **, size_t);
void pint(stack_t **, size_t);

stack_t *add_dnodeint_end(stack_t **, int);


#endif /*end of monty.h*/

