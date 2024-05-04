/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:11:47 by anamella          #+#    #+#             */
/*   Updated: 2024/05/04 20:24:48 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sa(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return (0);
	if ((*stack_a)->next == NULL)
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	return (0);
}

int	sb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return (0);
	if ((*stack_b)->next == NULL)
		return (0);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(&stack_a);
	sb(&stack_b);
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack_b;

	if (*stack_b == NULL)
		return (0);
	tmp_stack_b = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	f_add_node(stack_a, tmp_stack_b);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack_a;

	if (*stack_a == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	f_add_node(stack_b, tmp_stack_a);
	return (0);
}
