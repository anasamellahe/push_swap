#include "push_swap.h"

int algo_1_sort_b(stack **stack_a, stack **stack_b, stack * min)
{
    int len;
    int i;

    i = 0;
    len = link_len(*stack_a);
    while (check_top(*stack_a, min))
    {
        if (check_ps(*stack_a, min, len) == 1)
            ra(stack_a);
        else
            rra(stack_a);
    }
    if (check_top(*stack_a, min) == 0)
    {
        pb(stack_a, stack_b);
        return (1);
    }
    return (0);
}

void alogo_1(stack **stack_a, stack **stack_b, int divi)
{
    int key;
    int val;
    int len;
    int i;
    stack *stack_k;

    i = 0;
    stack_k = sort_k(*stack_a);
    len = link_len(*stack_a);
    key = ps_key(len / divi);
    val = get_index_val(stack_k, key);
    while (key <= len - ps_key(len / divi))
    {
        sort_algo_1(stack_a, stack_b, get_index_val(stack_k, key));
        key += ps_key(len / divi);
    }
    while (stack_a != NULL && i <= ps_key(len / divi))
    {
        sort_a(stack_a, stack_b);
        i++;
    }
    sort_in_a(stack_a, stack_b);
    
}
void sort_a(stack **stack_a, stack **stack_b)
{
    int len;
    int i;
    stack *max;

    i = 0;
    len = link_len(*stack_a);
    while (i < len / 2)
    {
        max = get_max(*stack_a);
        while (check_last(*stack_a, max))
        {
            if (check_ps(*stack_a, max, len) == 1)
                ra(stack_a);
            else
                rra(stack_a);
        }
        if (check_last(*stack_a, max) == 0)
            pb(stack_a, stack_b);
        i++;
    }
}

void sort_in_a(stack **stack_a, stack **stack_b)
{
    stack *test;
    while(*stack_b != NULL)
    {
        test = get_max(*stack_b);
        algo_1_sort_a(stack_a, stack_b, test);
    }
}

int algo_1_sort_a(stack **stack_a, stack **stack_b, stack * max)
{
    int len;
    int i;

    i = 0;
    len = link_len(*stack_b);
    while (check_top(*stack_b, max))
    {
        if (check_ps(*stack_b, max, len) == 1)
            rb(stack_b);
        else
            rrb(stack_b);
    }
    if (check_top(*stack_b, max) == 0)
    {
        pa(stack_a, stack_b);
        return (1);
    }
    return (0);
}

void sort_algo_1(stack **stack_a, stack **stack_b, int val)
{
    stack *tmp;
    stack *tmp_add;

    tmp = *stack_a;
    tmp_add = tmp;
    while (tmp != NULL)
    {
        if (tmp->data <= val)
        {
            algo_1_sort_b(stack_a, stack_b, tmp);
            tmp = *stack_a;
        }
        if ( tmp != NULL && tmp == tmp_add)
            tmp = tmp->next;
        else
            tmp =  tmp;
        tmp_add = tmp;
    }
}






/*_______________________________________________________*/


stack *get_best_move(stack *stack_a, stack *node, int val)
{
    get_best_move_from_top();
}
get_best_move_from_top(stack *stack_a, int val)
{
    
}