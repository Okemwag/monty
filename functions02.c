<<<<<<< HEAD
/**

* pall - prints the value of all items on the stack
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void
*/
=======
#include "monty.h"

/**
 * pall - prints the value of all items on the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
<<<<<<< HEAD
* pint - prints value at the top of the stack, plus new line
* @stack: pointer to stack
* @line_number: line number of instruction
* REturn: void
*/
=======
 * pint - prints value at the top of the stack, plus new line
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
void pint(stack_t **stack, unsigned int line_number)

{
	if (*stack == NULL)
	{
<<<<<<< HEAD
		fprintf(stderr,"L%d: can't pint, stack empty\n", line_number);
=======
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


<<<<<<< HEAD
/**
* pchar - prints the char at the top of the stack
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void
*/
=======

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n; /* head node's data */
	if (c < 0 || c > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(c);
	putchar('\n');
}

/**
<<<<<<< HEAD
* pstr - prints the string starting from the top of the stack
* @stack: pointer to stack
* line_number: line number of instruction
* REturn: void
*/
=======
 * pstr - prints the string starting from the top of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 * Return: void
 */
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
void pstr(stack_t **stack, unsigned int line_number)
{
	int c;
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		c = current->n; /* current node's data */
		if (c > 0 && c <= 127)
		{
<<<<<<< HEAD
current = current->next;
=======
			current = current->next;
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
			putchar(c);
		}
		else
			break;
	}
	putchar('\n');
<<<<<<< HEAD
} 
=======
}
>>>>>>> 3c2bc5c65240f4ba21d11e5cfed87686f8d48436
