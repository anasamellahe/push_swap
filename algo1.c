#include "push_swap.h"

t_stack	*sort_k(t_stack *stack_a)
{
	t_stack	*stack_k;
	t_stack	*head;
    t_stack *tmp;
    int		data;

	stack_k = dub(stack_a);
	tmp = stack_k;
	data = 0;
	head = stack_k;
	while (stack_k && stack_k->next != NULL)
    {
		tmp = stack_k->next;
		while (tmp != NULL)
		{
			if (stack_k->data > tmp->data)
			{
				data = stack_k->data;
				stack_k->data = tmp->data;
				tmp->data = data;
			}
			tmp = tmp->next;
		}
		stack_k = stack_k->next;
	}
	return (head);
}

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int		start;
	int		end;
	t_stack	*stack_k;

	stack_k = sort_k(*stack_a);
	start = 0;
	end = ((15 * (link_len(*stack_a) <= 100)) + (35 * (link_len(*stack_a) > 100)));
	while (*stack_a != NULL)
	{
		if (((*stack_a)->data >= get_index_val(stack_k, start)) && ((*stack_a)->data <= get_index_val(stack_k, end)))
		{
			pb(stack_a, stack_b);
			start += (start < (end - 1));
			end += end < link_len(*stack_a);
		}
		else if ((*stack_a)->data < get_index_val(stack_k, start))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start += (start < (end - 1));
			end += end < link_len(*stack_a);
		}
		else if ((*stack_a)->data > get_index_val(stack_k, end))
			ra(stack_a);
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
		len  = link_len(*stack_b);
		ps = check_ps(*stack_b, max, len);
		if (ps == 1)
			rb(stack_b);
		else if (ps == 2)
			rrb(stack_b);
		if (check_top(*stack_b, max))
			pa(stack_a, stack_b);
	}
}
int get_index(t_stack *stack, t_stack *node)
{
    int i;

    i = 0;
    while (stack != node)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}
void sort_2num(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
}
void sort_3num(t_stack **stack_a, t_stack **stack_b)
{
    int max;
    int min;

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
void sort_xnum(t_stack **stack_a, t_stack **stack_b)
{
    int ps;
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

t_stack *get_min(t_stack *stack_t)
{
    t_stack *tmp_stack;
    t_stack *tmp_stack1;

    tmp_stack1 = stack_t;
    tmp_stack = stack_t;
    while (stack_t != NULL)
    {
        tmp_stack = stack_t->next;
        while (tmp_stack != NULL)
        {
            if (tmp_stack->data < stack_t->data)
            {
                if (tmp_stack1->data > tmp_stack->data)
                  tmp_stack1 = tmp_stack;
            }
            else if (tmp_stack->data > stack_t->data)
            {
                if (tmp_stack1->data > stack_t->data)
                  tmp_stack1 = stack_t;
            }
            tmp_stack = tmp_stack->next;
        }
        stack_t = stack_t->next;
    }
    return (tmp_stack1);
}
void get_algo(t_stack **stack_a, t_stack **stack_b)
{
    int len;

    len = link_len(*stack_a);
    if (len == 2)
        sort_2num(stack_a, stack_b);
    else if (len == 3)
        sort_3num(stack_a, stack_b);
    else if (len > 3 && len <= 5)
        sort_xnum(stack_a, stack_b);
   
    else
        algo(stack_a, stack_b);
}