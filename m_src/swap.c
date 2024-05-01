#include "push_swap.h"

t_stack	*get_max(t_stack *stack_t)
{
	t_stack	*tmp_stack1;
	t_stack	*tmp_stack;

	tmp_stack1 = stack_t;
	tmp_stack = stack_t;
	while (stack_t != NULL)
	{
		tmp_stack = stack_t->next;
		while (tmp_stack != NULL)
		{
			if (tmp_stack->data > stack_t->data)
			{
				if (tmp_stack1->data < tmp_stack->data)
					tmp_stack1 = tmp_stack;
			}
			else if (tmp_stack->data < stack_t->data)
			{
				if (tmp_stack1->data < stack_t->data)
					tmp_stack1 = stack_t;
			}
			tmp_stack = tmp_stack->next;
		}
		stack_t = stack_t->next;
	}
	return (tmp_stack1);
}

int	check_ps(t_stack *stack_t, t_stack *node, int len)
{
	int	i;

	i = 0;
	while (node != NULL && stack_t != NULL && stack_t->data != node->data)
	{
		stack_t = stack_t->next;
		i++;
	}
	if (i <= (len / 2) && len > 1)
		return (1);
	else if (i >= (len / 2) && len > 1)
		return (2);
	return (0);
}

int	check_top(t_stack *head, t_stack *node)
{
	if (head == node || head->data == node->data)
		return (1);
	else
		return (0);
}

t_stack	*dub(t_stack *stack_a)
{
	t_stack	*stack_k;

	stack_k = NULL;
	while (stack_a != NULL)
	{
		l_add_node(&stack_k, new_node(stack_a->data));
		stack_a = stack_a->next;
	}
	return (stack_k);
}

int	get_index_val(t_stack *stack_k, int index)
{
	int	i;

	i = 0;
	while (stack_k != NULL && stack_k->next != NULL && i != index)
	{
		stack_k = stack_k->next;
		i++;
	}
	return (stack_k->data);
}
