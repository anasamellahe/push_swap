#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//#include "libft/libft.h"

typedef struct node
{
    int data;
    struct node *next;
}stack;

int ft_strlen(char *s);
int ft_strcmp(char *s, char *s1);
int is_number(char *s);
int is_int(char *s);
int is_dup(char **av, int ac);
int ft_atoi(char *s);
int check_error(char **av, int ac);
stack *new_node (int data);
void l_add_node(stack **head, stack *node_to_add);
void f_add_node(stack **head, stack * node_to_add);
void print_node(stack *head);
int link_len(stack *stack_t);
void free_node(stack * stack_free);


int sa(stack * stack_a);
int sb(stack * stack_b);
int ss(stack *stack_a, stack *stack_b);
int pa(stack **stack_a, stack **stack_b);
int pb(stack **stack_a, stack **stack_b);
int ra(stack ** stack_a);
int rb(stack ** stack_b);
int rr(stack ** stack_a, stack **stack_b);
int rra(stack **stack_a);
int rrb(stack **stack_b);
int rrr(stack **stack_a, stack **stack_b);


int check_ps(stack *stack_t, stack * node,int len); 
stack *get_min(stack *stack_t);


void sort_b(stack **stack_a, stack **stack_b);
int check_last(stack *head, stack *node);
int check_top(stack *head, stack *node);
stack *get_max(stack *stack_t);


stack *dub(stack *stack_a);
stack *sort_k(stack *stack_a);
void alogo_1(stack **stack_a, stack **stack_b);
void sort_algo_1(stack **stack_a, stack **stack_b, int val);
int algo_1_sort_b(stack **stack_a, stack **stack_b, stack * min);
int get_index_val(stack *stack_k, int index);
int ps_key(float key);



void print_stack(stack *stack_a);

int algo_1_sort_a(stack **stack_a, stack **stack_b, stack * max);
void sort_in_a(stack **stack_a, stack **stack_b);
#endif