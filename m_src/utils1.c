/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:02:23 by anamella          #+#    #+#             */
/*   Updated: 2024/05/02 12:37:25 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_k(t_stack *stack_a)
{
	t_stack	*stack_k;
	t_stack	*head;
	t_stack	*tmp;
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

int	get_index(t_stack *stack, t_stack *node)
{
	int	i;

	i = 0;
	while (stack != node)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*get_min(t_stack *stack_t)
{
	t_stack	*tmp_stack;
	t_stack	*tmp_stack1;

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

void	get_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	start;
	int	end;

	len = link_len(*stack_a);
	if (len == 2)
		sort_2num(stack_a, stack_b);
	else if (len == 3)
		sort_3num(stack_a, stack_b);
	else if (len > 3 && len <= 5)
		sort_xnum(stack_a, stack_b);
	else
	{
		start = 0;
		end = ((15 * (len <= 100)) + (35 * (len > 100)));
		algo(stack_a, stack_b, start, end);
	}
}

int	is_empty(char *s)
{
	int	i;
	
	i = 0;
	while (s && s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}