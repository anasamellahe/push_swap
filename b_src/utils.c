/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:12:00 by anamella          #+#    #+#             */
/*   Updated: 2024/05/04 20:16:41 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s, char *s1)
{
	int	i;

	i = 0;
	while (s && s1 && s[i] == s1[i] && s[i] && s1[i])
		i++;
	return (s[i] - s1[i]);
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
