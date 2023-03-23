#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds the top values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a monty bytecodes file
 * Description: The result is stored in the second value node
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, 'add'));
	}
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}
/**
 * monty_sub - Substract the secound value
 * @stack: A pointer to top mode node of a stack_t linked list
 * @line_number: The current working line number of a monty
 * Description: result
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}
	 (*stack)->next->next->n -= (*stack)->next->n;
        monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the second value from the top of a stack_t
 * @stack: A pointer to top mode node of a stack_t linked list
 * @line_number: The current working line number of a monty
 * Description: the result
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}
/**
 * monty_mul - multiplies the second value from top
 * @stack: A pointer to the top mode node of a stack _t
 * @line_number: The current working line_number
 *
 * Description: the result is stored
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}
/**
 * monty_mod - Computer the modules of the second value
 * @stack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number
 * Description: The result
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next-> == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}
	(*stack)->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
