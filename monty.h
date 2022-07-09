#ifndef MONTY_H
#define MONTY_H

/* LIBRARIES */
#define  _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>

#define DELIM " "

/* STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct free_s - handle variables for free
 * @line_read: line from file readed
 * @file: file readed
 * @head: head in the double linked list
**/
typedef struct free_s
{
	char *line_read;
	FILE *file;
	stack_t *head;
} free_t;


/* MAIN FUNCTIONS */
/*print error msg in standard error*/
void print_err(int err_code, int line_number, char *opcode);
void free_exit(int, int, char *);
/**
* find_built - find if the built-in sended exists or not
* @num_line: file line counter
* @line_number: file line counter
* Return: always void
**/
void (*find_built(int num_line, char *opcode))(stack_t **stack,
															   unsigned int line_number);

/*find respective function and execute.*/
void execute(stack_t **, char *, size_t);
/*free all double linked list*/
void free_stack(stack_t *head);


/* BUILT-IN FUNCTIONS */
/*prints all the elements of a stack_t list*/
void _pall(stack_t **, unsigned int);
/*adds a new node at the beginning of a dlistint_t list*/
void _push(stack_t **head, unsigned int num_line, char *token_num);
/*prints the value at the top of the stack, followed by a new line*/
void _pint(stack_t **head, unsigned int line_number);
/* Delete node in double linked list*/
void _pop(stack_t **, unsigned int);
/*swaps the top two elements of the stack*/
void _swap(stack_t **head, unsigned int line_number);
/*sum the first two elements in one of them*/
void _add(stack_t **head, unsigned int line_num);
/*doesn't do anything*/
void _nop(stack_t **head, unsigned int line_number);
/*sub the first two elements in one of them*/
void _sub(stack_t **head, unsigned int line_num);
/*div the first two elements in one of them*/
void _div(stack_t **head, unsigned int line_num);
/*mul the first two elements in one of them**/
void _mul(stack_t **head, unsigned int line_num);
/*mod the first two elements in one of them*/
void _mod(stack_t **head, unsigned int line_num);
/*prints the char at the top of the stack*/
void _pchar(stack_t **head, unsigned int line_number);
/*prints the string starting at the top of the stack*/
void _pstr(stack_t **head, unsigned int line_number);

/* TOOLS */
/**/
FILE *validate_path(int argc, char *argv[], FILE *file);
/*validate if two strings are equals*/
int _strcmp(char *str1, char *str2);
/*cut into diferent strings the first two args from a line*/
int tokenize(char *, char **);
/*validate is string have only space*/
int only_space(char *string);
/*counts the number of elements in a linked stack_t list*/
size_t len_list(const stack_t *head);
#endif
