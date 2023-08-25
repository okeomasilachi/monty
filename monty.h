#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

#define V (void)
#define ERR 2

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct opcode - extern struct for the monty interpreter
 * @num: holdes values for the push opcode
 * @que: changes the data (stack) type to either queue of stack
 * @line: holds the command from each line on line per time
 * @stack: holdes the stack
 *
 * Description: stack, queues, LIFO, FIFO
 */
typedef struct opcode
{
	char *num;
	bool que;
	char *line;
	stack_t *stack;
} Monty;

extern Monty *mo;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void remov(char *str);
void __int(void);
void line_space(char *cmd);
bool num_only(const char *str);
int value(void);


void free_s(stack_t *stack);
struct instruction_s *_opcode(const char *opcode);
FILE  *file_handle(int argc, char *av);
instruction_t *op_cd(char *line, unsigned int line_number);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void free_all(void);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
