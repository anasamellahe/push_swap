#include "checker.h"

int  get_moves(t_stack **stack_a, t_stack **stack_b)
{
    char *s;

    s = get_next_line(0);
    while (s)
    {
       if (moves_check(s, stack_a, stack_b))
            return (-1);
        s = get_next_line(0);
    }
    return (0);
}
int moves_check(char *s, t_stack **stack_a, t_stack **stack_b)
{
    if (!ft_strcmp(s, "sa\n"))
        sa(stack_a);
    else if (!ft_strcmp(s, "sb\n"))
        sb(stack_b);
    else if (!ft_strcmp(s, "ss\n"))
        ss(*stack_a, *stack_b);
    else if (!ft_strcmp(s, "pa\n"))
        pa(stack_a, stack_b);
    else if (!ft_strcmp(s, "pb\n"))
        pb(stack_a, stack_b);
    else if (!ft_strcmp(s, "ra\n"))
        ra(stack_a);
    else if (!ft_strcmp(s, "rb\n"))
        rb(stack_b);
    else if (!ft_strcmp(s, "rr\n"))
        rr(stack_a, stack_b);
    else if (!ft_strcmp(s, "rra\n"))
        rra(stack_a);
    else if (!ft_strcmp(s, "rrb\n"))
        rrb(stack_b);
    else if (!ft_strcmp(s, "rrr\n"))
         rrr(stack_a, stack_b);
    else
        return (1);
    return(0);
}
