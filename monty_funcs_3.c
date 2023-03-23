#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Does absolutely nothing for the monty opcode 'nop'
 * @stack: A pointer to the top mode of a stack_t linked list
 * @link_number: The current working line number
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * monty_pchar - Does absolutely nothing for the monty opcode 'nop'
 * @stack: A pointer to the top mode of a stack_t linked list
 * @link_number: The current working line number
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number, "value out of range"));
		return;
	}
	printf("%\n", (*stack)->next->n);
}
/**
 * monty_pstr - prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode of a stack_t linked list
 * @link_number: The current working line number
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp-> 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
