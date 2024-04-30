#include "push_swap.h"

void algo(t_stack **stack_a, t_stack **stack_b)
{
    int     stack_len;
    int     start;
    int     end;
    t_stack *stack_k;

 
    stack_k = sort_k(*stack_a);
    stack_len = link_len(*stack_a);
    start = 0;
    end = ((15 * (stack_len <= 100)) + (35 * (stack_len > 100)));
    while(*stack_a != NULL)
    {
        if (((*stack_a)->data >= get_index_val(stack_k, start)) && ((*stack_a)->data <= get_index_val(stack_k, end)))
        {
            pb(stack_a, stack_b);
            start += (start < (end - 1));
            end += end < stack_len;
        }
        else if ((*stack_a)->data < get_index_val(stack_k, start))
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            start += (start < (end - 1));
            end += end < stack_len;
        }
        else if ((*stack_a)->data > get_index_val(stack_k, end))
            ra(stack_a);
    }
    sort_to_a(stack_a, stack_b);
}
void sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int     ps;
    int     len;
    t_stack *max;

    while (*stack_b != NULL)
    {
       
        max = get_max(*stack_b);
        len  = link_len(*stack_b);
        ps = check_ps(*stack_b, max, len);
        if (ps == 1)
            rb(stack_b);
        else if (ps == 2)
            rrb(stack_b);
        if (check_top(*stack_b, max))
            pa(stack_a, stack_b);
    }
}