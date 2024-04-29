#include "push_swap.h"

void algo(t_stack **stack_a, t_stack **stack_b)
{
    int     stack_len;
    int     start;
    int     end;
    t_stack *stack_k;

    start = 0;
    end = ((15 * (stack_len <= 100)) + (35 * (stack_len > 100)));
    stack_k = sort_k(*stack_a);
    stack_len = link_len(*stack_a);
    while(*stack_a != NULL)
    {
        if (((*stack_a)->data >= get_index_val(stack_k, start)) && ((*stack_a)->data <= get_index_val(stack_k, end)))
            pb(stack_a, stack_b);
        else if ((*stack_a)->data < get_index_val(stack_k, start))
        {
            pb(stack_a, stack_b);
            rb(stack_b);
        }
        else if ((*stack_a)->data > get_index_val(stack_k, end))
            ra(stack_a);
        if (!(*stack_a)->data > get_index_val(stack_k, end))
        {
            start++;
            end++;
        }
    }


}