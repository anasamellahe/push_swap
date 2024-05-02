#include "push_swap.h"

void    set_stack(t_stack **stack_a, t_stack **stack_b, char **str)
{
	int	i;

	i = 0;
	while (str[i])
			l_add_node(stack_a, new_node(ft_atoi(str[i++])));
	if (!is_sorted(*stack_a, *stack_b))
		get_algo(stack_a, stack_b);
	if (*stack_a)
		free_node(*stack_a);
	if (*stack_b)
		free_node(*stack_b);
	ft_free(str);
}
