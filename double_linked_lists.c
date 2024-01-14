#include "monty.h"

stack_t
*add_dnodeint_end(stack_t **head, int n)
{
	stack_t *newNode, *lastP;

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

	lastP = top;

	lastP->next = newNode;
	newNode->prev = lastP;
	top = newNode;

	return (newNode);
}
