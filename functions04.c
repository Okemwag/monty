#include "monty.h"

/**
 * stack_length - returns length of stack
 * @stack: pointer to head of stack
 * Return: length of stack
 */
size_t stack_length(stack_t **stack)
{
	stack_t *current;
	unsigned int n; /* counter for number of elements */

	current = *stack;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}

/**
 * free_stack - frees a stack_t stack
 * @stack: stack to be freed
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
 * free_all - frees line and fp
 * @stack: stack to free
 * @line: line to free from getline
 * @fp: file pointer to free
 * Return: void
 */
void free_all(stack_t *stack, char *line, FILE *fp)
{
	if (stack != NULL)
		free_stack(&stack);

	free(line);
	fclose(fp);
}
