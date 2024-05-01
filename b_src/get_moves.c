#include "checker.h"

int  get_moves(t_stack **stack_a, t_stack **stack_b)
{
    char *s;

    s = get_next_line(0);
    while (s)
    {
       if (moves_check(s, stack_a, stack_b))
        {
            write (2, "Error\n", 6);
            if (*stack_a != NULL)
                free_node(*stack_a);
            if (*stack_b != NULL)
                free_node(*stack_b);
            return (-1);
        }
        s = get_next_line(0);
    }
    return (0);
}
int moves_check(char *s, t_stack **stack_a, t_stack **stack_b)
{
    if (!ft_strcmp(s, "sa"))
        sa(stack_a);
    else if (!ft_strcmp(s, "sb"))
        sb(stack_b);
    else if (!ft_strcmp(s, "ss"))
        ss(stack_a, stack_b);
    else if (!ft_strcmp(s, "pa"))
        pa(stack_a, stack_b);
    else if (!ft_strcmp(s, "pb"))
        pb(stack_a, stack_b);
    else if (!ft_strcmp(s, "ra"))
        ra(stack_a);
    else if (!ft_strcmp(s, "rb"))
        rb(stack_b);
    else if (!ft_strcmp(s, "rr"))
        rr(stack_a, stack_b);
    else if (!ft_strcmp(s, "rra"))
        rra(stack_a);
    else if (!ft_strcmp(s, "rrb"))
        rrb(stack_b);
    else if (!ft_strcmp(s, "rrr"))
         rrr(stack_a, stack_b);
    else
        return (1);
    return(0);
}
