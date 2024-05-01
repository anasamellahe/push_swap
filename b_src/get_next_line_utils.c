/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:05:29 by anamella          #+#    #+#             */
/*   Updated: 2024/05/01 22:20:25 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	len1;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	if (s2)
		len1 = ft_strlen(s2);
	else
		len1 = 0;
	ptr = malloc(len + len1 + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_memcpy(ptr, s1, len);
	if (s2)
		ft_memcpy((ptr + len), s2, len1);
	ptr[len + len1] = '\0';
	if (s1)
		free((char *)s1);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*t;

	t = dst;
	if (dst == src)
		return (t);
	while (n)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src++);
		n--;
	}
	return (t);
}

