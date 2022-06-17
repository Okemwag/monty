#include "monty.h"

/**
* _add - adds top two elements of stack, removes top element, and replaces 
* the value of the top element with the sum
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	result = a + b;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
* _sub - subtracts top two elements of stack, removes top elements, and
* replaces the value of the top element with the difference
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	result = b -a;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
* _mul - multiplies top two elements of stack, removes top element, and 
* replaces the value of the top element with the product
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	result = a * b;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
* _div - divides top two elements of stack, removes top element, and replaces
* the value of the top element with the quotient
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = b / a;

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
* _mod - divides top two elements of stack, removes top element, and replaces
* the value of the top element with the reminder
* @stack: pointer to stack
* @line_number: line number of instruction
* Return: void, exit with -1 on failure
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;
	int result;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = b % a;

	pop(stack, line_number);

	(*stack)-> = result;
}
