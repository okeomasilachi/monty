#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	int lt;
	stack_t *new, *temp;

	(void)line_number, (void)temp, (void)new;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	temp = (*stack);
	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
	}
	lt = (*stack)->n;
	(*stack) = temp;
	temp = (*stack);
	while ((*stack)->next->next != NULL)
	{
		(*stack) = (*stack)->next;
	}
	(*stack)->next->prev = NULL;
	free((*stack)->next);
	(*stack)->next = NULL;
	(*stack) = temp;
	temp = malloc(sizeof(stack_t));
	temp->n = lt;
	temp->prev = NULL;
	(*stack)->prev = temp;
	temp->next = (*stack);
	(*stack) = temp;
}

/**
 * stack - sets the format of the data to a stack (LIFO).
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
	if (mo->que != false)
		mo->que = false;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: pointer to the stark to push to
 * @line_number: the current line where the command is comming from
 *
 * Return: void
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
	if (mo->que != true)
		mo->que = true;
}
