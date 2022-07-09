#include "monty.h"
/**
 * free_stack - free all double linked list
 * @head: stack_t first node
 * Return: always void
 */
void free_stack(stack_t *head)
{
	/*edge case*/
	if (!head)
		return;
	/* normal */
	if (head->prev)
		free(head->prev);
	/* case base */
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	/* recursion */
	free_stack(head->next);
}
