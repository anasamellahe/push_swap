#include "push_swap.h"

int sa(t_stack ** stack_a)
{
	t_stack *tmp;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return (0);

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	printf("sa\n");
	return (0);
}
int sb(t_stack ** stack_b)
{
	t_stack *tmp;

	if (stack_b == NULL || (*stack_b)->next == NULL)
		return (0);

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	printf("sb\n");
	return (0);
}
int ss(t_stack * stack_a, t_stack * stack_b)
{
	sa(&stack_a);
	sb(&stack_b);
	printf("ss\n");
	return (0);
}
int pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_stack_b;

	if (stack_b == NULL)
		return (0);
	tmp_stack_b = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	f_add_node(stack_a, tmp_stack_b);
	printf("pa\n");
	return (0);
}
int pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_stack_a;

	if (stack_a == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	f_add_node(stack_b, tmp_stack_a);
	printf("pb\n");
	return (0);
}
