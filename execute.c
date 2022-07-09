#include "monty.h"
/**
 * execute - find respective function and execute.
 * @head: stack
 * @instruction: instruction with args
 * @num_line: line of monty file
 */
void execute(stack_t **head, char *instruction, size_t num_line)
{
	char *tokens[2];
	/* validate is null instruction*/
	if (!instruction)
		free_exit(2, num_line, instruction); /*print error*/
	/* tokenize */
	tokenize(instruction, tokens);

	if (tokens[0][0] ==  '#') /*find comments*/
		return;

	if (!strcmp(tokens[0], "push")) /* find push*/
	{
		_push(head, num_line, tokens[1]);
		return;
	}
	/* find built-in*/
	find_built(num_line, tokens[0])(head, num_line);
}
