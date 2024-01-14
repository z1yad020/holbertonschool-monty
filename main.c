#include "monty.h"

stack_t
*top = NULL;

void
dispose(stack_t **head)
{
	stack_t *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp);
	}
}


int
main(int ac, char **argv)
{
	FILE *fmonty;
	char buff[BUFSIZ], *fopcode = NULL;
	size_t line_number = 0;
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fmonty = fopen(argv[1], "r");
	if (!fmonty)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buff, BUFSIZ, fmonty) != NULL)
	{
		line_number++;
		fopcode = strtok(buff, DELIM);

		/* empty or space(tab)-only line case  */
		if (!fopcode)
			continue;

		execvecommand(&head, fopcode, line_number);
	}

	fclose(fmonty);
	dispose(&head);
	return (0);
}
