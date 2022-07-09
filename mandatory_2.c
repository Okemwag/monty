#include "monty.h"

/**
 * _push - adds a new node at the beginning of a dlistint_t list
* @head: head in the dobly linked list
* @line_number: file line counter
* @token_num: parameter for execute push
* Return: always void
 **/
void _push(stack_t **head, unsigned int line_number, char *token_num)
{
	stack_t *new_node = NULL;
	int num;

	if (!head)
	{
		free_exit(3, line_number, "push");
		return;
	}
	if (!token_num)
	{
		free_exit(6, line_number, "push");
		return;
	}
	if (token_num[0] == '0')
		num = 0;
	else
	{
		num = atoi(token_num);
		if (num == 0)
			free_exit(6, line_number, "push");
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_exit(5, line_number, NULL);
		return;
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *head;
	/*now new_node will point to what head pointed before*/
	if (*head != NULL)
		/*here we ask: if what head is pointing isn't NULL...do*/
		(*head)->prev = new_node;
	*head = new_node;
}

/**
* _swap - swaps the top two elements of the stack
* @head: head in the dobly linked list
* @line_number: file line counter
* Return: always void
**/
void _swap(stack_t **head, unsigned int line_number)
{
	int num_elements = 0, tmp_num = 0;

	if (head == NULL)
	{
		/* error: "the stack is empty";*/
		free_exit(4, line_number, "swap");
		return;
	}
	num_elements = len_list(*head);
	if (num_elements < 2)
	{
		/* error: "L<line_number>: can't swap, stack too short"; */
		free_exit(4, line_number, "swap");
		return;
	}
	tmp_num = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp_num;
}
/**
* _pstr - prints the string starting at the top of the stack
* @head: head in the dobly linked list
* @line_number: file line counter
* Return: always void
**/
void _pstr(stack_t **head, unsigned int line_number)
{
	char string[100];
	size_t i = 0;
	stack_t *tmp = (*head);

	(void)line_number;
	if (head == NULL)
		return;

	while (tmp != NULL)
	{
		if (tmp->n == 0)
			break;
		if (tmp->n >= 32 && tmp->n <= 127)
		{
			string[i] = tmp->n;
			i++;
		}
		tmp = tmp->next;
	}
	string[i] = '\0';
	if (string != NULL)
		printf("%s", string);
	printf("\n");
}

/**
* _pchar - prints the char at the top of the stack
* @head: head in the dobly linked list
* @line_number: file line counter
* Return: always void
**/
void _pchar(stack_t **head, unsigned int line_number)
{
	int c;

	if (!head || *head == NULL)
	{
		free_exit(4, line_number, "pchar");
		return;
	}
	c = (*head)->n;
	if (c < 32 || c > 127)
	{
		free_exit(9, line_number, NULL);
	}
	printf("%c\n", c);
}
