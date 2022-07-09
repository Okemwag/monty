#include "monty.h"
/**
* _add - adds the top two elements of the stack
* @head: head in the dobly linked list
* @line_num: file line counter
* Return: always void
**/
void _add(stack_t **head, unsigned int line_num)
{
	int num_elements = 0;
	stack_t *tmp;

	if (head == NULL)
	{
		free_exit(4, line_num, "add");
		return;
	}
	num_elements = len_list(*head);
	if (num_elements < 2)
	{
		free_exit(4, line_num, "add");
		return;
	}
	tmp = (*head);
	/*here the values that are inside the first two nodes*/
	/*are added together in the second node*/
	(*head)->next->n = ((*head)->n + (*head)->next->n);
	(*head) = (*head)->next;
	/*at this point head now points to what used to be the second node*/
	(*head)->prev = NULL;
	/*free the unnecessary node*/
	free(tmp);
}
/**
* _sub - subs the top two elements of the stack
* @head: head in the dobly linked list
* @line_num: file line counter
* Return: always void
**/
void _sub(stack_t **head, unsigned int line_num)
{
	int num_elements = 0;
	stack_t *tmp;

	if (head == NULL)
	{
		free_exit(4, line_num, "sub");
		return;
	}
	num_elements = len_list(*head);
	if (num_elements < 2)
	{
		free_exit(4, line_num, "sub");
		return;
	}
	tmp = (*head);
	/*here the values that are inside the first two nodes*/
	/*are sub together in the second node*/
	(*head)->next->n = ((*head)->n - ((*head)->next->n));
	(*head) = (*head)->next;
	/*at this point head now points to what used to be the second node*/
	(*head)->prev = NULL;
	/*free the unnecessary node*/
	free(tmp);
}
/**
* _div - divides the top two elements of the stack
* @head: head in the dobly linked list
* @line_num: file line counter
* Return: always void
**/
void _div(stack_t **head, unsigned int line_num)
{
	int num_elements = 0;
	stack_t *tmp;

	if (head == NULL)
	{
		free_exit(4, line_num, "div");
		return;
	}
	num_elements = len_list(*head);
	if (num_elements < 2)
	{
		free_exit(4, line_num, "div");
		return;
	}
	tmp = (*head);
	if ((*head)->n == '0')
	{
		free_exit(8, line_num, "div");
		return;
	}
	/*here the values that are inside the first two nodes*/
	/*are divided together in the second node*/
	(*head)->next->n = (((*head)->n) / ((*head)->next->n));
	(*head) = (*head)->next;
	/*at this point head now points to what used to be the second node*/
	(*head)->prev = NULL;
	/*free the unnecessary node*/
	free(tmp);
}
/**
* _mul - multiplies the top two elements of the stack
* @head: head in the dobly linked list
* @line_num: file line counter
* Return: always void
**/
void _mul(stack_t **head, unsigned int line_num)
{
	int num_elements = 0;
	stack_t *tmp;

	if (head == NULL)
	{
		free_exit(4, line_num, "mul");
		return;
	}
	num_elements = len_list(*head);
	if (num_elements < 2)
	{
		free_exit(4, line_num, "mul");
		return;
	}
	tmp = (*head);
	/*here the values that are inside the first two nodes*/
	/*are sub together in the second node*/
	(*head)->next->n = (((*head)->n) * ((*head)->next->n));
	(*head) = (*head)->next;
	/*at this point head now points to what used to be the second node*/
	(*head)->prev = NULL;
	/*free the unnecessary node*/
	free(tmp);
}

/**
* _mod - divides the top two elements of the stack
* @head: head in the dobly linked list
* @line_num: file line counter
* Return: always void
**/
void _mod(stack_t **head, unsigned int line_num)
{
	int num_elements = 0;
	stack_t *tmp;

	if (head == NULL)
	{
		free_exit(4, line_num, "mod");
		return;
	}
	num_elements = len_list(*head);
	if (num_elements < 2)
	{
		free_exit(4, line_num, "mod");
		return;
	}
	tmp = (*head);
	if ((*head)->n == '0')
	{
		free_exit(8, line_num, "mod");
		return;
	}
	/*here the values that are inside the first two nodes*/
	/*are module together in the second node*/
	(*head)->next->n = (((*head)->n) % ((*head)->next->n));
	(*head) = (*head)->next;
	/*at this point head now points to what used to be the second node*/
	(*head)->prev = NULL;
	/*free the unnecessary node*/
	free(tmp);
}
