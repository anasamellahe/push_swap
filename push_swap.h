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

int ft_strlen(char *s);
int ft_strcmp(char *s, char *s1);
int is_number(char *s);
int is_int(char *s);
int is_dup(char **av, int ac);
int ft_atoi(char *s);
int check_error(char **av, int ac);
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
t_stack *get_min(t_stack *stack_t);



void sort_b(t_stack **stack_a, t_stack **stack_b);
int check_last(t_stack *head, t_stack *node);
int check_top(t_stack *head, t_stack *node);
t_stack *get_max(t_stack *stack_t);


t_stack *dub(t_stack *stack_a);
t_stack *sort_k(t_stack *stack_a);
void alogo_1(t_stack **stack_a, t_stack **stack_b, int divi);
void sort_algo_1(t_stack **stack_a, t_stack **stack_b, int val);
int algo_1_sort_b(t_stack **stack_a, t_stack **stack_b, t_stack * min);
int get_index_val(t_stack *stack_k, int index);
int ps_key(float key);
void sort_a(t_stack **stack_a, t_stack **stack_b);



void print_stack(t_stack *stack_a);

int algo_1_sort_a(t_stack **stack_a, t_stack **stack_b, t_stack * max);
void sort_in_a(t_stack **stack_a, t_stack **stack_b);


void sort_algo_1(t_stack **stack_a, t_stack **stack_b, int val);
int check_va(t_stack * stack_a, int val);
t_stack *get_best_move(t_stack *stack_a, int val);
t_stack *get_index_node(t_stack *stack_a, int index);
int get_best_move_from_top(t_stack *stack_a, int val);
int get_best_move_from_last(t_stack *stack_a, int val);

void algo(t_stack **stack_a, t_stack **stack_b);

#endif