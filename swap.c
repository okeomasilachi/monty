#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);
	int n, k;

	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = temp->n;
	k = temp->next->n;
	temp->n = k;
	temp->next->n = n;
	(*stack) = temp;
	n = '\0';
	k = '\0';
}
