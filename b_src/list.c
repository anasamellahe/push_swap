#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	l_add_node(t_stack **head, t_stack *node_to_add)
{
	t_stack	*tmp_head;

	tmp_head = (*head);
	if ((*head) != NULL)
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = node_to_add;
		(*head) = tmp_head;
	}
	else
		(*head) = node_to_add;
}

int	link_len(t_stack *stack_t)
{
	int	i;

	i = 0;
	while (stack_t != NULL)
	{
		stack_t = stack_t->next;
		i++;
	}
	return (i);
}

void	f_add_node(t_stack **head, t_stack *node_to_add)
{
	node_to_add->next = (*head);
	(*head) = node_to_add;
}

void	free_node(t_stack *stack_free)
{
	t_stack	*tmp;

	while (stack_free->next != NULL)
	{
		tmp = stack_free;
		stack_free = stack_free->next;
		free(tmp);
	}
	free(stack_free);
}
