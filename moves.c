#include "push_swap.h"

int sa(stack * stack_a)
{
	int tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
    while (stack_a->next->next != NULL)
		stack_a = stack_a->next;
	tmp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = tmp;
}
int sb(stack * stack_b)
{
	int tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return (0);
    while (stack_b->next->next != NULL)
		stack_b = stack_b->next;
	tmp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = tmp;
}
int ss(stack * stack_a, stack * stack_b)
{
	sa(stack_a);
	sb(stack_b);
	return (0);
}
int pa(stack *stack_a, stack *stack_b)
{
	if (stack_b == NULL)
		return (0);
	while (stack_b->next != NULL)
		stack_b = stack_b->next;
	l_add_node(stack_a, stack_b);
	return (0);
}
int pb(stack * stack_a, stack *stack_b)
{
	if (stack_a == NULL)
		return (0);
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	l_add_node(stack_b, stack_a);
	return (0);
}
int ra(stack ** stack_a)
{
	stack * tmp_stack_a;
	stack * tmp_p_stack_a;
	if ((*stack_a) == NULL|| (*stack_a)->next == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	while(tmp_stack_a->next != NULL)
	{
		if (tmp_stack_a->next->next == NULL)
			tmp_p_stack_a = tmp_stack_a;
		tmp_stack_a = tmp_stack_a->next;
	}
	f_add_node(stack_a, tmp_stack_a);
	tmp_p_stack_a->next = NULL;
	return (0);
}
int rb(stack ** stack_b)
{
	stack * tmp_stack_b;
	stack * tmp_p_stack_b;
	if ((*stack_b) == NULL|| (*stack_b)->next == NULL)
		return (0);
	tmp_stack_b = (*stack_b);
	while(tmp_stack_b->next != NULL)
	{
		if (tmp_stack_b->next->next == NULL)
			tmp_p_stack_b = tmp_stack_b;
		tmp_stack_b = tmp_stack_b->next;
	}
	f_add_node(stack_b, tmp_stack_b);
	tmp_p_stack_b->next = NULL;
	return (0);
}
int rr(stack **stack_a, stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	return (0);
}
int rra(stack **stack_a)
{
	stack	*tmp_stack_a;
	stack	*tmp_p_stack_a;
	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp_stack_a->next = NULL;
	l_add_node(stack_a, tmp_stack_a);
	return (0);
	
}