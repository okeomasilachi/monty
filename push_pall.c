#include "monty.h"

/**
 * _digits - cheaks if a string is all numbers
 * @ptr: pointer to the string
 *
 * Return: true if string is all integers else false
*/
bool _digits(char *ptr)
{
	while (*ptr)
	{
		if (!isdigit(*ptr))
			return (false);
		ptr++;
	}
	return (true);
}

/**
 * push - pushes to a stack
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (mo->num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (_digits(mo->num))
	{
		new = malloc(sizeof(stack_t));
		new->n = atoi(mo->num);
		new->prev = NULL;
		new->next = (*stack);
		(*stack) = new;
	}
}

/**
 * pall - prints all the values in a stark
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = mo->stack;

	V line_number, V stack;
	if (cur == NULL)
		return;
	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
