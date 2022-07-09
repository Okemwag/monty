#include "monty.h"
/**
* find_built - find if the built-in sent exists or not
* @num_line: file line counter
* @line_number: file line counter
* Return: always void
**/
void (*find_built(int num_line, char *opcode))(stack_t **head,
															   unsigned int line_number)
{
	size_t i;

	instruction_t options[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}};

	for (i = 0; options[i].opcode != NULL; i++)
		if (_strcmp(options[i].opcode, opcode))
			return (options[i].f);

	/* case invalid instruction*/
	free_exit(2, num_line, opcode);
	return (NULL);
}
