/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:02:16 by anamella          #+#    #+#             */
/*   Updated: 2024/05/04 20:14:54 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	i += (s[i] == '-' || s[i] == '+');
	if (s[i] == 0)
		return (-1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	is_int(char *s)
{
	long	n;

	n = ft_atoi(s);
	if (n > (long)(2147483647) || n < (long)(-2147483648))
		return (-1);
	return (0);
}

int	is_dup(char **str)
{
	int	i;
	int	j;
	int	argc;

	i = 0;
	argc = 0;
	while (str[argc] != NULL)
		argc++;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_stack(t_stack **stack_a, t_stack **stack_b, char **str)
{
	int	i;

	i = 0;
	while (str[i])
		l_add_node(stack_a, new_node((int)(ft_atoi(str[i++]))));
	if (!is_sorted(*stack_a, *stack_b))
		get_algo(stack_a, stack_b);
	if (*stack_a)
		free_node(*stack_a);
	if (*stack_b)
		free_node(*stack_b);
	ft_free(str);
}
