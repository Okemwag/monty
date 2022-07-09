#include "monty.h"
/**
* _nop - doesn't do anything
* @head: head in the dobly linked list
* @line_number: file line counter
* Return: always void
**/
void _nop(stack_t **head, unsigned int line_number)
{
	(void)(*head);
	(void)line_number;
}

/**
* _pall - prints all the elements of a stack_t list
* @head: head in the dobly linked list
* @line_number: file line counter
* Return: always void
**/
void _pall(stack_t **head, unsigned int line_number)
{
	size_t i = 0;
	stack_t *tmp;

	(void)line_number;
	tmp = (*head);
	if (head == NULL)
	{
		return;
	}
	while (tmp != NULL)
	{
		i++;
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* _pint - prints the value at the top of the stack, followed by a new line
* @head: head in the dobly linked list
* @line_number: file line counter
* Return: always void
**/
void _pint(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{

		free_exit(7, line_number, "pint");
		return;
	}
	printf("%d\n", (*head)->n);
}

/**
* _pop - Delete node in double linked list
* @head: head  the dobly linked list
* @line_num: file line counter
* Return: always void
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = *head;

	if (head == NULL || *head == NULL)
	{
		free_exit(3, line_num, "pop");
		return;
	}
	if ((*head)->next == NULL)
	{
		free(tmp);
		(*head) = NULL;
		return;
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}
