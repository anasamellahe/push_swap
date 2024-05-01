#include "push_swap.h"

void	algo(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
	int		flag;
	t_stack	*stack_k;

	stack_k = sort_k(*stack_a);
	while (*stack_a != NULL)
	{
		flag = 1;
		if (((*stack_a)->data >= get_index_val(stack_k, start))
			&& ((*stack_a)->data <= get_index_val(stack_k, end)))
			pb(stack_a, stack_b);
		else if ((*stack_a)->data < get_index_val(stack_k, start))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if ((*stack_a)->data > get_index_val(stack_k, end))
		{
			flag = 0;
			ra(stack_a);
		}
		start += (start < (end - 1)) * flag;
		end += (end < (link_len(*stack_a) + link_len(*stack_b))) * flag;
	}
	sort_to_a(stack_a, stack_b);
	free_node(stack_k);
}

void	sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		ps;
	int		len;
	t_stack	*max;

	while (*stack_b != NULL)
	{
		max = get_max(*stack_b);
		len = link_len(*stack_b);
		ps = check_ps(*stack_b, max, len);
		if (ps == 1)
			rb(stack_b);
		else if (ps == 2)
			rrb(stack_b);
		if (check_top(*stack_b, max))
			pa(stack_a, stack_b);
	}
}

void	sort_2num(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	sa(stack_a);
}

void	sort_3num(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	(void)stack_b;
	max = get_index(*stack_a, get_max(*stack_a));
	min = get_index(*stack_a, get_min(*stack_a));
	if (min == 1 && max == 2)
		sa(stack_a);
	if (min == 2 && max == 0)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (min == 1 && max == 0)
		ra(stack_a);
	if (min == 0 && max == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (min == 2 && max == 1)
		rra(stack_a);
}

void	sort_xnum(t_stack **stack_a, t_stack **stack_b)
{
	int	ps;

	while (link_len(*stack_a) > 3)
	{
		ps = check_ps(*stack_a, get_min(*stack_a), link_len(*stack_a));
		if (ps == 1)
			ra(stack_a);
		else if (ps == 2)
			rra(stack_a);
		if (check_top(*stack_a, get_min(*stack_a)))
			pb(stack_a, stack_b);
	}
	sort_3num(stack_a, stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}
