#include "monty.h"

/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to a node on the stack
 * @n: line number
 */
void _pint(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to a node on the stack
 * @n: line number
 */
void _pchar(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}


/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to a node on the stack
 * @n: line number
 */
void _pstr(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stdout, "\n");
		return;
	}

	node = *stack;
	while (node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		fprintf(stdout, "%c", node->n);
		node = node->next;
	}
	fprintf(stdout, "\n");
}

/**
 * _rotl - rotates the stack to the top
 * @stack: pointer to a node on the stack
 * @n: line number
 */
void _rotl(stack_t **stack, unsigned int n)
{
	stack_t *h = NULL, *t = NULL;

	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	h = *stack;
	t = h->next;
	t->prev = NULL;
	*stack = t;
	while (t->next)
	{
		t = t->next;
	}
	t->next = h;
	h->prev = t;
	h->next = NULL;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to a node on the stack
 * @n: line number
 */
void _rotr(stack_t **stack, unsigned int n)
{
	stack_t *h = NULL, *t = NULL;

	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	t = h = *stack;
	 /* save address of second node */
	while (h->next)
		h = h->next;

	h->prev->next = NULL;
	h->next = t;
	h->prev = NULL;
	t->prev = h;
	*stack = h;
}
