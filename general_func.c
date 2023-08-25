#include "monty.h"

/**
 * __int - intialize values in struct Monty
 *
 * Return: void
*/
void __int(void)
{
	mo = malloc(sizeof(Monty));
	mo->line = NULL;
	mo->num = NULL;
	mo->que = false;
	mo->stack = NULL;
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

/**
 * num_only - cheaks if a string is all numbers
 * @str: pointer to the string
 *
 * Return: true if string is all integers else false
*/
bool num_only(const char *str)
{
	static int isNegative;

	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '-')
	{
		isNegative++;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);

		str++;
	}

	return (true);
}

/**
 * value - checks if a value in fomat char is negative
 *
 * Return: Neagtive int is char is negative
 * else positive int is returned
*/
int value(void)
{
	static int isNegative;
	int value;

	if (isNegative == 1)
	{
		isNegative = 0;
		value = atoi(mo->num);
		value = 0 - value;
		return (value);
	}
	else
	{
		return (atoi(mo->num));
	}
}
