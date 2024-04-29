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
int ra(t_stack ** stack_a)
{
	t_stack *tmp_stack_a;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp_stack_a->next = NULL;
	l_add_node(stack_a, tmp_stack_a);
	printf("ra\n");
	return (0);
}
int rb(t_stack ** stack_b)
{
	t_stack *tmp_stack_b;
	
	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return (0);
	tmp_stack_b = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp_stack_b->next = NULL;
	l_add_node(stack_b, tmp_stack_b);
	printf("rb\n");
	return (0);
}
int rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr\n");
	return (0);
}
int rra(t_stack **stack_a)
{
	t_stack *tmp_stack_a;
	t_stack *tmp;

	tmp_stack_a = (*stack_a);
	while (tmp_stack_a->next->next != NULL)
		tmp_stack_a = tmp_stack_a->next;
	tmp = tmp_stack_a->next;
	tmp_stack_a->next = NULL;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	printf("rra\n");
	return (0);
}
int rrb(t_stack **stack_b)
{
	t_stack *tmp_stack_b;
	t_stack *tmp;

	tmp_stack_b = (*stack_b);
	while (tmp_stack_b->next->next != NULL)
		tmp_stack_b = tmp_stack_b->next;
	tmp = tmp_stack_b->next;
	tmp_stack_b->next = NULL;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	printf("rrb\n");
	return (0);
}
int rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr\n");
	return (0);
}
