#include "monty.h"

stack_t
*add_dnodeint_end(stack_t **head, int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (!newNode || !head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = NULL;

	if (!*head)
	{
		newNode->prev = NULL;
		*head = newNode;
		top = newNode;
		return (newNode);
	}

	top->next = newNode;
	newNode->prev = top;
	top = newNode;

	return (newNode);
}

/*
stack_t
*delete_dnodeint_at_end(stack_t **head)
{
	if (!(*head))
		return (NULL);

	if (top->prev)
	{
		top->prev->next = NULL;
		free(top->prev);
		top->prev = NULL;

		top = top->prev;
	}
	else
	{
		*head = NULL;
		top->next = NULL;
		top->prev = NULL;
	}

	return (dlist);
}*/
