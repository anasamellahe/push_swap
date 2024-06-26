/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:11:52 by anamella          #+#    #+#             */
/*   Updated: 2024/05/04 20:43:19 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_stack **stack_a)
{
	t_stack	*tmp_stack_a;

	if ((*stack_a) == NULL)
		return (0);
	if ((*stack_a)->next == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp_stack_a->next = NULL;
	l_add_node(stack_a, tmp_stack_a);
	return (0);
}

int	rb(t_stack **stack_b)
{
	t_stack	*tmp_stack_b;

	if ((*stack_b) == NULL)
		return (0);
	if ((*stack_b)->next == NULL)
		return (0);
	tmp_stack_b = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp_stack_b->next = NULL;
	l_add_node(stack_b, tmp_stack_b);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	return (0);
}

int	rra(t_stack **stack_a)
{
	t_stack	*tmp_stack_a;
	t_stack	*tmp;

	if (*stack_a == NULL)
		return (0);
	if ((*stack_a)->next == NULL)
		return (0);
	tmp_stack_a = (*stack_a);
	while (tmp_stack_a->next->next != NULL)
		tmp_stack_a = tmp_stack_a->next;
	tmp = tmp_stack_a->next;
	tmp_stack_a->next = NULL;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	return (0);
}

int	rrb(t_stack **stack_b)
{
	t_stack	*tmp_stack_b;
	t_stack	*tmp;

	if (*stack_b == NULL)
		return (0);
	if ((*stack_b)->next == NULL)
		return (0);
	tmp_stack_b = (*stack_b);
	while (tmp_stack_b->next->next != NULL)
		tmp_stack_b = tmp_stack_b->next;
	tmp = tmp_stack_b->next;
	tmp_stack_b->next = NULL;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	return (0);
}
