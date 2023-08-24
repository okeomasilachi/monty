#include "monty.h"

/**
 * empty - checks if an address pointed to by a pointer is empty
 * @str: string to be checked
 *
 * Return: 0 if empty else 1
*/
int empty(const char *str)
{
	while (*str)
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}


/**
 * remov - removes all occurance of "\n\t"" in a string
 * @str: string to be processed
 *
 * Return: Void
*/
void remov(char *str)
{
	int i, j;
	char *src, *dst;

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != '\a' &&
			str[i] != '\b' && str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	src = str;
	dst = str;
	while (*src)
	{
		if (*src != '"')
		{
			*dst = *src;
			dst++;
		}
		src++;
	}
	*dst = '\0';
}

/**
 * line_space - funtions removes concurent white spaces from a string
 * @cmd: the string to be worked on
 *
 * Return: void
*/
void line_space(char *cmd)
{
	char *new;

	if (cmd == NULL || *cmd == '\0')
		return;

	while (*cmd != '\0' && strchr(" \t\n\r\a\b\v\f\r", *cmd) == NULL)
		cmd++;

	new = cmd;
	while (*cmd != '\0')
	{
		if (*cmd == ' ')
		{
			while (*(cmd + 1) == ' ')
				cmd++;
		}
		*new = *cmd;
		cmd++;
		new++;
	}
	*new = '\0';
}
