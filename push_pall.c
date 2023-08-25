#include "monty.h"

/**
 * free_all - free's all alloacation by getline
 *
 * Return: void
*/
void free_all(void)
{
	if (mo->line != NULL)
		free(mo->line);
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

	if (num_only(mo->num) == false || mo->num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		new = malloc(sizeof(stack_t));
		new->n = value();
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

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->n == '\0')
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_s((*stack));
		free_all();
		free(mo);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
