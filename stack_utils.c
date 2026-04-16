#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_front(t_stack **stack, t_stack *node)
{
	if (!node)
		return ;
	node->next = *stack;
	node->prev = NULL;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

t_stack	*pop_front(t_stack **stack)
{
	t_stack	*node;

	if (!*stack)
		return (NULL);
	node = *stack;
	*stack = node->next;
	if (*stack)
		(*stack)->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
