/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:01:28 by anamella          #+#    #+#             */
/*   Updated: 2024/05/01 23:01:30 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
