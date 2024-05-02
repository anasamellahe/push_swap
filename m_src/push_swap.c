/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:02:03 by anamella          #+#    #+#             */
/*   Updated: 2024/05/02 12:46:52 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

int	main(int ac, char **av)
{
	char	**str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		str = new_str(av);
		if (str == NULL || check_error(str) == -1)
		{
			write(2, "Error\n", 6);
			if (str)
				ft_free(str);
			return (0);
		}
		set_stack(&stack_a, &stack_b, str);
	}
	return (0);
}
