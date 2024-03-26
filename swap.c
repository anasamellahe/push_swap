#include "push_swap.h"


stack *get_min(stack *stack_t)
{
    stack *i;
    stack *tmp_stack;

    i = stack_t;
    tmp_stack = stack_t;
    while (stack_t != NULL)
    {
        tmp_stack = stack_t->next;
        while (tmp_stack != NULL)
        {
            if (tmp_stack->data < stack_t->data)
            {
                if (i->data > tmp_stack->data)
                  i = tmp_stack;
            }
            else if (tmp_stack->data > stack_t->data)
            {
                if (i->data > stack_t->data)
                  i = stack_t;
            }
            tmp_stack = tmp_stack->next;
        }
        stack_t = stack_t->next;
    }
    return (i);
}
stack *get_max(stack *stack_t)
{
    stack *i;
    stack *tmp_stack;

    i = stack_t;
    tmp_stack = stack_t;
    while (stack_t != NULL)
    {
        tmp_stack = stack_t->next;
        while (tmp_stack != NULL)
        {
            if (tmp_stack->data > stack_t->data)
            {
                if (i->data < tmp_stack->data)
                  i = tmp_stack;
            }
            else if (tmp_stack->data < stack_t->data)
            {
                if (i->data < stack_t->data)
                  i = stack_t;
            }
            tmp_stack = tmp_stack->next;
        }
        stack_t = stack_t->next;
    }
    return (i);
}
int check_ps(stack *stack_t, stack * node,int len)
{
	int i;

	i = 0;
	while (node != NULL && stack_t != NULL && stack_t->data != node->data)
	{
		stack_t = stack_t->next;
		i++;
	}
	if (i < (len / 2))
		return (1);
	else
		return (-1);
}
int check_top(stack *head, stack *node)
{
    if (head == node)
        return (0);
    else
        return (1);
}
int check_last(stack *head, stack *node)
{
    while (head != NULL && head->next != NULL)
        head = head->next;
    if (head == node)
        return (0);
    else
        return (1);
}

void sort_b(stack **stack_a, stack **stack_b)
{
    int len;
    int i;
    stack *min;

    i = 0;
    len = link_len(*stack_a);
    while (i < len / 2)
    {
        min = get_min(*stack_a);
        while (check_top(*stack_a, min))
        {
            if (check_ps(*stack_a, min, len) == 1)
                ra(stack_a);
            else
                rra(stack_a);
        }
        if (check_top(*stack_a, min) == 0)
            pb(stack_a, stack_b);
        i++;
    }
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
stack *dub(stack *stack_a)
{
    stack *stack_k;

    stack_k = NULL;
    while (stack_a != NULL)
    {
        l_add_node(&stack_k, new_node(stack_a->data));
        stack_a = stack_a->next;
    }
    return (stack_k);   
}
stack *sort_k(stack *stack_a)
{
    stack *stack_k;
    stack *head;
    stack *tmp;
    int   data;

    stack_k = dub(stack_a);
    tmp = stack_k;
    data = 0;
    head = stack_k;
    while (stack_k && stack_k->next != NULL)
    {
        tmp = stack_k->next;
        while (tmp != NULL)
        {
            if (stack_k->data > tmp->data)
            {
                data = stack_k->data;
                stack_k->data = tmp->data;
                tmp->data = data;
            }
            tmp = tmp->next;
        }
        stack_k = stack_k->next;
    }
    return (head);
}
int ps_key(float key)
{
    int tmp_key;

    tmp_key = (int)key;
    if (key - tmp_key >= 0.5)
        return ((int)(key + 1));
    else
        return (key);   
}
int get_index_val(stack *stack_k, int index)
{
    int i;

    i = 0;
    while (stack_k != NULL && stack_k->next != NULL  && i != index)
    {
        stack_k = stack_k->next;
        i++;
    }
    return (stack_k->data);
}


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
void alogo_1(stack **stack_a, stack **stack_b)
{
    int key;
    int val;
    int len;
    stack *stack_k;

    stack_k = sort_k(*stack_a);
    len = link_len(*stack_a);
    key = ps_key(len / 4);
    val = get_index_val(stack_k, key);
    while (key <= len)
    {
        sort_algo_1(stack_a, stack_b, get_index_val(stack_k, key));
        key += ps_key(len / 4);
    }
    sort_in_a(stack_a, stack_b);
    
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
        //printf("test %p\n", *stack_b);
        pa(stack_a, stack_b);
        return (1);
    }
    return (0);
}