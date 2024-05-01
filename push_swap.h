#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//#include "libft/libft.h"

typedef struct s_stack
{
    int data;
    struct s_stack *next;
}   t_stack;

void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int ft_strlen(const char *s);
int ft_strcmp(char *s, char *s1);
int is_number(char *s);
int is_int(char *s);
int is_dup(char **av);
int ft_atoi(const char *s);
int check_error(char **str);
t_stack *new_node (int data);
void l_add_node(t_stack **head, t_stack *node_to_add);
void f_add_node(t_stack **head, t_stack * node_to_add);
void print_node(t_stack *head);
int link_len(t_stack *stack_t);
void free_node(t_stack * stack_free);

int sa(t_stack ** stack_a);
int sb(t_stack ** stack_b);
int ss(t_stack *stack_a, t_stack *stack_b);
int pa(t_stack **stack_a, t_stack **stack_b);
int pb(t_stack **stack_a, t_stack **stack_b);
int ra(t_stack ** stack_a);
int rb(t_stack ** stack_b);
int rr(t_stack ** stack_a, t_stack **stack_b);
int rra(t_stack **stack_a);
int rrb(t_stack **stack_b);
int rrr(t_stack **stack_a, t_stack **stack_b);


int check_ps(t_stack *stack_t, t_stack * node,int len); 
int check_top(t_stack *head, t_stack *node);
t_stack *get_max(t_stack *stack_t);


t_stack *dub(t_stack *stack_a);
t_stack *sort_k(t_stack *stack_a);
int get_index_val(t_stack *stack_k, int index);

void print_stack(t_stack *stack_a);

void algo(t_stack **stack_a, t_stack **stack_b);
void sort_to_a(t_stack **stack_a, t_stack **stack_b);
char	**ft_split(char const *s, char c);
char	**ft_free(char **ptr);

void sort_3num(t_stack **stack_a, t_stack **stack_b);
void sort_xnum(t_stack **stack_a, t_stack **stack_b);
int get_index(t_stack *stack, t_stack *node);
t_stack *get_min(t_stack *stack_t);
void get_algo(t_stack **stack_a, t_stack **stack_b);
#endif