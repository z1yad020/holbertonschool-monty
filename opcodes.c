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
		dispose(head);
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

void
pint(stack_t **head, size_t line_number)
{
	if (!head || !(*head) || !top)
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}


void
pop(stack_t **head, size_t line_number)
{
	if (!head || !(*head) || !top)
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->prev)
	{
		top = top->prev;
		free(top->next);
		top->next = NULL;
	}
	else
	{
		free(top);
		top = NULL;
		*head = NULL;
	}
}
