/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:03:16 by anamella          #+#    #+#             */
/*   Updated: 2024/05/02 12:57:47 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**new_str(char **av)
{
	int		i;
	char	*new;
	char	**new_sp;

	i = 1;
	new = 0;
	while (av[i] != NULL)
	{
		if (*av[i] == 0 || is_empty(av[i]))
		{
			if (new)
				free(new);
			return (NULL);
		}
		new = ft_strjoin(new, av[i]);
		if (av[i + 1] != NULL)
			new = ft_strjoin(new, " ");
		i++;
	}
	new_sp = ft_split(new, ' ');
	free(new);
	return (new_sp);
}

int	set_stack(t_stack **stack_a, t_stack **stack_b, char **str)
{
	int	i;

	i = 0;
	while (str[i])
		l_add_node(stack_a, new_node(ft_atoi(str[i++])));
	ft_free(str);
	if (get_moves(stack_a, stack_b))
	{
		write(1, "Error\n", 6);
		if (*stack_a)
			free_node(*stack_a);
		if (*stack_b)
			free_node(*stack_b);
		return (1);
	}
	return (0);
}

int	check_error(char **str)
{
	int	i;

	i = 0;
	if (is_dup(str) != 0)
		return (-1);
	while (str[i] != NULL)
	{
		if (is_int(str[i]) != 0 || is_number(str[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*i;
	t_stack	*j;

	i = stack_a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->data > j->data)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1 * (stack_b == NULL));
}

int	main(int ac, char *av[])
{
	char	**str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	str = new_str(av);
	if (str == NULL || check_error(str) == -1)
	{
		write(2, "Error\n", 6);
		if (str)
			ft_free(str);
		return (0);
	}
	if (set_stack(&stack_a, &stack_b, str))
		return (0);
	if (is_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stack_a, stack_b);
	return (0);
}
