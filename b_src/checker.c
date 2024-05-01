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
		new = ft_strjoin(new, av[i]);
		if (av[i + 1] != NULL)
			new = ft_strjoin(new, " ");
		i++;
	}
	new_sp = ft_split(new, ' ');
	free(new);
	return (new_sp);
}

int set_stack(t_stack **stack_a, t_stack **stack_b, char **str)
{
	int	i;

	i = 0;
	while (str[i])
		l_add_node(stack_a, new_node(ft_atoi(str[i++])));
	ft_free(str);
	if (!is_sorted(*stack_a))
		if (get_moves(stack_a, stack_b))
		{
			write(1, "Error\n", 6);
			if (*stack_a)
				free_node(*stack_a);
			if (*stack_b)
				free_node(*stack_b);
			return (0);
		}
	if (is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (*stack_a)
		free_node(*stack_a);
	if (*stack_b)
		free_node(*stack_b);
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

int	is_sorted(t_stack *stack_a)
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
	return (1);
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
int main(int ac, char *av[])
{
	char	**str;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	(void)ac;
	stack_a = NULL;
	stack_b = NULL;
	str = new_str(av);
	if (check_error(str) == -1)
	{
		write(2, "Error\n", 6);
		ft_free(str);
		return (0);
	}
	set_stack(&stack_a, &stack_b, str);
}

