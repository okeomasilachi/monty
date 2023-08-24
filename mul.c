#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 *		with the top element of the stack.
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = ((*stack)->next->n * (*stack)->n);
	new->prev = NULL;
	pop(stack, line_number);
	pop(stack, line_number);
	new->next = (*stack);
	(*stack) = new;
}
