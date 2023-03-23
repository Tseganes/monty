#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
/**
 * init_stack - initializes a stack with beginning stack and ending queue
 * @stack: A pointer to an unitialized
 * Return: if an error occurs - EXIT_FAILURE
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());
	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}
/**
 * check_mode - Check if a stack_t linked list is in stack or queue mode
 * @stack: A pointer to the top (stack) or bottom (queue)
 * Return: if the stack_t is in stack mode (0),
 *         if the stack_t is in queue mode (0),
 *         otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}