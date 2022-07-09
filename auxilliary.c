#include "monty.h"
/**
 *  _strcmp - validate if two strings are equals.
 *  @str1: text one.
 *  @str2: text two.
 *  Return: If the texts are equal 1, or else 0.
 */
int _strcmp(char *str1, char *str2)
{
	/* edge case */
	if (!str1 || !str2)
		return (0);

	/* if case base failure*/
	if (*str1 != *str2)
		return (0);

	/* if case base success*/
	if (!*str1 && !*str2)
		return (1);

	/* recursion case */
	return (_strcmp(str1 + 1, str2 + 1));
}
/**
 * tokenize - cut into diferent strings the first two args from a line
 * @opcode: line sended
 * @tokens: the diferent strings
 * Return: 0 on success
 **/
int tokenize(char *opcode, char **tokens)
{
	size_t i;
	char *token;

	for (i = 0; 1; i++)
	{
		token = strtok(((i == 0) ? opcode : NULL), DELIM);
		if (token == NULL || i == 2)
		{
			return (0);
		}
		tokens[i] = token;
	}
	return (1);
}
/**
 * len_list - counts the number of elements in a linked stack_t list
 * @h: head in the dobly linked list
 * Return: the number of elements in a linked stack_t list
 **/
size_t len_list(const stack_t *h)
{
	size_t i = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}
/**
 * only_space - validate is string have only space
 * @string: char * to validate
 * Return: 0 o 1 is only spaces
 */
int only_space(char *string)
{
	size_t i;

	if (!string)
		return (0);

	if (string[0] == '\0')
		return (1);

	for (i = 0; string[i] ; i++)
	{
		if (string[i] != ' ')
			return (0);
	}
	return (1);
}
/**
 * validate_path - checks the correct format and access from a file
 * @argc: num of parameters sended
 * @argv: strings of parameters sended
 * @file: file information
 * Return: FILE data
 **/
FILE *validate_path(int argc, char *argv[], FILE *file)
{
	if (argc != 2)
		free_exit(0, 0, NULL);
	/* free_exit */

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		free_exit(1, 0, argv[1]);
	}
	return (file);
}
