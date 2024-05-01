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
