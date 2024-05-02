#include "checker.h"

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

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a)
        free_node(stack_a);
    if (stack_b)
        free_node(stack_b);
}