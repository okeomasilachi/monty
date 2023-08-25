#include "monty.h"
#include "dic.h"
#include <stdio.h>


/**
 * free_s - free's memory allocated for a stack
 * @stack: The stack to free
 *
 * Return: void
*/
void free_s(stack_t *stack)
{
	if (stack == NULL)
		return;
	free_s(stack->next);
	free(stack);
}

/**
 * _opcode - gets the function to run from the command
 * @opcode: command from the command line
 *
 * Return: void
*/
struct instruction_s *_opcode(const char *opcode)
{
	unsigned long i;
	static struct instruction_s opcodes[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"sub", sub}, {"div", Div},
		{"nop", nop}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
	};

	for (i = 0; i < sizeof(opcodes) / sizeof(opcodes[0]); i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (&opcodes[i]);
	}
	return (NULL);
}

/**
 * file_handle - handles all file processing
 * @argc: argument count
 * @av: argument vectors
 *
 * Return: ponter of type FILE
*/
FILE  *file_handle(int argc, char *av)
{
	FILE *file = NULL;

	V argc, V av;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * op_cd - does the funtion setting for execution
 * @line: the command to run
 * @line_number: the number of the current line being executed
 *
 * Return: pointer of type instruction_t
*/
instruction_t *op_cd(char *line, unsigned int line_number)
{
	instruction_t *opcode;

	opcode = _opcode(line);
	if (opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
	}
	return (opcode);
}



/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	FILE *file;
	unsigned int line_number = 1;
	ssize_t r;
	instruction_t *opcode = NULL;
	size_t line_length = 0;
	char *tok;

	file = file_handle(argc, argv[1]);
	__int();
	while (1)
	{
		r = getline(&mo->line, &line_length, file);
		if (r == EOF)
			break;
		while (*mo->line != '\0' && strchr("\t\n\r \v\f\b\a", *mo->line) != NULL)
			mo->line++;
		line_space(mo->line), remov(mo->line);
		if (strchr("\t\n\r \v\f\b\a#", *mo->line) != NULL)
		{
			line_number++;
			continue;
		}
		tok = strtok(mo->line, "\t\n\r \v\f\b\a");
		mo->line = tok;
		if (strcmp(mo->line, "push") == 0)
		{
			tok = strtok(NULL, "\t\n\r \v\f\b\a");
			if (tok)
				mo->num = tok;
			else
				mo->num = NULL;
		}
		opcode = op_cd(mo->line, line_number);
		opcode->f(&mo->stack, line_number);
		line_number++;
	}
	free_s(mo->stack), free_all(), free(mo);
	fclose(file);
	return (EXIT_SUCCESS);
}
