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


void
swap(stack_t **head, size_t line_number)
{
	stack_t *tmp;

	if (!head || !*head || !top->prev)
	{
		fprintf(stderr, "L%lu: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!top->prev->prev)
	{
		tmp = *head;

		*head = (*head)->next;
		(*head)->prev = NULL;
		(*head)->next = tmp;

		tmp->prev = *head;
		tmp->next = NULL;

		top = tmp;
		return;
	}

	/* second from back */
	tmp = top->prev;

	top->prev->prev->next = top;
	top->next = top->prev;
	top->prev = tmp->prev;

	tmp->prev = tmp->next;
	tmp->next = NULL;

	top = tmp;
}


void
add(stack_t **head, size_t line_number)
{
	if (!head || !*head || !top->prev)
	{
		fprintf(stderr, "L%lu: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->prev->n += top->n;
	pop(head, line_number);
}


void
nop(stack_t **head, size_t line_number)
{
	(void) head;
	(void) line_number;
}
