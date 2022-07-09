#include "monty.h"

free_t *free_data;

/**
 * main - monty interpreter
 * @argc: args counter
 * @argv: args values
 * Return: exit status
 */
int main(int argc, char *argv[])
{
	/*declaration variables*/
	size_t buffer_size = 0, num_line = 1;
	ssize_t char_read = 0;

	free_data = malloc(sizeof(free_t));
	if (free_data == NULL)
	{
		free_exit(5, 0, NULL);
		return (EXIT_FAILURE);
	}
		
	/* validate path */

	free_data->head = NULL;
	free_data->file = NULL;
	free_data->line_read = NULL;

	free_data->file = validate_path(argc, argv, free_data->file);
	/* initialize stack */

	/* read file*/
	for (num_line = 1; char_read != EOF; num_line++)
	{
		/*recordar liberar el malloc de getline*/
		char_read = getline(&(free_data->line_read), &buffer_size, free_data->file);
		if (char_read == -1)
		{
			free_exit(99, num_line, NULL);
		}
		if (free_data->line_read[char_read - 1] == '\n')
		{
			/*para eliminar el caracter '/n'*/
			free_data->line_read[char_read - 1] = '\0';
		}
		if (only_space(free_data->line_read))
			continue;
		execute(&(free_data->head), free_data->line_read, num_line);/* execute */
	}
	return (EXIT_SUCCESS);
}
/**
 * free_exit - handle free and exit
 * @line_num: counter from the file readed
 * @err_code: code for find an especific error
 * @opcode: string for manage an especific error
 * Return: always void
 **/
void free_exit(int err_code, int line_num, char *opcode)
{
	if (free_data->head != NULL) /* frees */
		free_stack(free_data->head);
	print_err(line_num, err_code, opcode);
	free_data->head = NULL;

	free(free_data->line_read);
	fclose(free_data->file);
	free(free_data);
	if (err_code == 99)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
