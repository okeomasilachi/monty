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
	stack_t *new, *nxt = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_s((*stack));
		free_all(mo->line);
		free(mo);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = ((*stack)->next->n * (*stack)->n);
	new->prev = NULL;
	/* removing the first and second values */
	nxt = (*stack)->next;
	(*stack)->next = NULL;
	nxt->prev = NULL;
	free(*stack);
	(*stack) = nxt;

	nxt = (*stack)->next;
	(*stack)->next = NULL;
	nxt->prev = NULL;
	free(*stack);
	(*stack) = nxt;
	/* pushing the values */
	new->next = (*stack);
	(*stack) = new;
}

/**
 * mod - computes the rest of the division of the second top element
 *		of the stack by the top element of the stack.
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *nxt = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_s((*stack));
		free_all(mo->line);
		free(mo);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_s((*stack));
		free_all(mo->line);
		free(mo);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = ((*stack)->next->n % (*stack)->n);
	new->prev = NULL;
	/* removing the first and second values */
	nxt = (*stack)->next;
	(*stack)->next = NULL;
	nxt->prev = NULL;
	free(*stack);
	(*stack) = nxt;

	nxt = (*stack)->next;
	(*stack)->next = NULL;
	nxt->prev = NULL;
	free(*stack);
	(*stack) = nxt;
	/* pushing the value */
	new->next = (*stack);
	(*stack) = new;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_s((*stack));
		free_all(mo->line);
		free(mo);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 1)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_s((*stack));
		free_all(mo->line);
		free(mo);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 *		followed by a new line
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if ((*stack) == NULL)
	{
		putchar('0');
		putchar('\n');
	}
	temp = (*stack);
	while (temp != NULL)
	{
		if (temp->n == 0)
			break;
		if (temp->n > 127 || temp->n < 1)
			break;
		printf("%c", (char)temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *new, *cur, *temp, *nxt;

	V line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	i = (*stack)->n;
	nxt = (*stack)->next;
	(*stack)->next = NULL;
	nxt->prev = NULL;
	free(*stack);
	(*stack) = nxt;
	new = malloc(sizeof(stack_t));
	new->n = i;
	new->next = NULL;
	temp = (*stack);
	cur = temp;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = new;
	new->prev = cur;
	(*stack) = temp;
}
