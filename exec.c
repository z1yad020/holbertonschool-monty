#include "monty.h"

instruction_t
opcodes[8] = {
	{"push", push},
	{"pall", pall},
	/*      {"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nope", nope},*/
	{NULL, NULL}
};

void
execvecommand(stack_t **head, char *fopcode, size_t line_number)
{
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (!strcmp(opcodes[i].opcode, fopcode))
		{
			opcodes[i].f(head, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr,	"L%lu: unknown instruction %s\n", line_number, fopcode);
	dispose(*head);
	exit(EXIT_FAILURE);
}
