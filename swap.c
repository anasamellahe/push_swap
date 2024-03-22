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
int check_ps(stack *stack_t, stack * node,int len)
{
	int i;

	i = 0;
	while (node != NULL && stack_t != NULL && stack_t->data != node->data)
	{
		stack_t = stack_t->next;
		i++;
	}
	printf ("i == %d\n", i);
	if (i < (len / 2))
		return (1);
	else
		return (-1);
	
}