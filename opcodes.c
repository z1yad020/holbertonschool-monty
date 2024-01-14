#include "monty.h"

int
isint(char *tok)
{
	if (!tok)
		return (0);

	if (*tok == '-')
		tok++;
	
	while (*tok)
		if (*tok >= '0' && *tok <= '9')
			tok++;
		else
			return (0);


	return (1);
}


void
push(stack_t **head, size_t line_number)
{
	char *tok = strtok(NULL, DELIM);
	int data;

	if (!tok || !isint(tok))
	{
		dispose(*head);
		fprintf(stderr, "L%lu: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = atoi(tok);

	add_dnodeint_end(head, data);
}

void
pall(stack_t **head, size_t line_number)
{
	const stack_t *node = top;
	
	(void) head;
	(void) line_number;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}