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

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_s((*stack));
		free_all();
		free(mo);	
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

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_s((*stack));
		free_all();
		free(mo);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = ((*stack)->n + (*stack)->next->n);
	new->prev = NULL;
	pop(stack, line_number);
	pop(stack, line_number);
	new->next = (*stack);
	(*stack) = new;
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
}

/**
 * sub - subtracts the top element of the stack from
 *		the second top element of the stack.
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_s((*stack));
		free_all();
		free(mo);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = ((*stack)->next->n - (*stack)->n);
	new->prev = NULL;
	pop(stack, line_number);
	pop(stack, line_number);
	new->next = (*stack);
	(*stack) = new;
}

/**
 * Div - divides the second top element of the stack
 *		by the top element of the stack
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void Div(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_s((*stack));
		free_all();
		free(mo);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_s((*stack));
		free_all();
		free(mo);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = ((*stack)->next->n / (*stack)->n);
	new->prev = NULL;
	pop(stack, line_number);
	pop(stack, line_number);
	new->next = (*stack);
	(*stack) = new;
}
