#include "monty.h"
#include <string.h>

void free_token(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims');
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);
/**
 * free_tokens - frees the global op_toks
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;
	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);
	free(op_toks);
}
/**
 * token_arr_len - Gets the length of current op_toks
 *
 * Return: length of current op_toks
 */
unsigned int tiken_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_roks[toks_len])
		toks_len++;
	return (toks_len);
}
/**
 * is_empty_line - check if a line read from getline on;y contain delimiter
 * @line: A pointer to the line
 * @delims: A string of delimiter
 *
 * Return: if the line only contains delimiters -1.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}
/**
 * get_op_func - matches an opcode
 * @opcode: The opcode to match
 *
 * Return: A pointer to corresponding
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rot1", monty_rot1},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}
/**
 * run_monty - primary function to excute a monty
 * @script_fd: File descriptor for an open monty
 *
 * Return: EXIT_SUCCESS
 */
int run_monty(FILE*script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return(EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_token();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_token();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_token();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_status);
}
