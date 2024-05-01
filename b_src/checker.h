#ifndef CHECKER_H
#define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_stack
{
    int data;
    struct s_stack *next;
}   t_stack;

char	**new_str(char **av);
int	check_error(char **str);
int	is_sorted(t_stack *stack_a);
char	**ft_free(char **ptr);

int	ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

t_stack	*new_node(int data);
void	l_add_node(t_stack **head, t_stack *node_to_add);
int	link_len(t_stack *stack_t);
void	f_add_node(t_stack **head, t_stack *node_to_add);
void	free_node(t_stack *stack_free);

int	sa(t_stack **stack_a);
int	sb(t_stack **stack_b);
int	ss(t_stack *stack_a, t_stack *stack_b);
int	pa(t_stack **stack_a, t_stack **stack_b);
int	pb(t_stack **stack_a, t_stack **stack_b);
int	ra(t_stack **stack_a);
int	rb(t_stack **stack_b);
int	rr(t_stack **stack_a, t_stack **stack_b);
int	rra(t_stack **stack_a);
int	rrb(t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);

int	ft_strlen(const char *s);
int	ft_strcmp(char *s, char *s1);
int	is_number(char *s);
int	is_int(char *s);
int	is_dup(char **str);
#endif