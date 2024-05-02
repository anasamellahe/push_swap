/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:02:06 by anamella          #+#    #+#             */
/*   Updated: 2024/05/02 12:43:31 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack	*get_max(t_stack *stack_t);
t_stack	*new_node(int data);
t_stack	*dub(t_stack *stack_a);
t_stack	*sort_k(t_stack *stack_a);
t_stack	*get_min(t_stack *stack_t);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	l_add_node(t_stack **head, t_stack *node_to_add);
void	f_add_node(t_stack **head, t_stack *node_to_add);
void	free_node(t_stack *stack_free);
void	sort_2num(t_stack **stack_a, t_stack **stack_b);
void	sort_3num(t_stack **stack_a, t_stack **stack_b);
void	sort_xnum(t_stack **stack_a, t_stack **stack_b);
void	algo(t_stack **stack_a, t_stack **stack_b, int start, int end);
void	set_stack(t_stack **stack_a, t_stack **stack_b, char **str);
void	sort_to_a(t_stack **stack_a, t_stack **stack_b);
void	get_algo(t_stack **stack_a, t_stack **stack_b);

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**ft_free(char **ptr);

int		check_ps(t_stack *stack_t, t_stack *node, int len);
int		get_index_val(t_stack *stack_k, int index);
int		get_index(t_stack *stack, t_stack *node);
int		check_top(t_stack *head, t_stack *node);
int		ft_strcmp(char *s, char *s1);
int		is_sorted(t_stack *stack_a, t_stack *stack_b);
int		link_len(t_stack *stack_t);
int		ft_strlen(const char *s);
int		check_error(char **str);
int		ft_atoi(const char *s);
int		is_number(char *s);
int		is_dup(char **av);
int		is_int(char *s);
int		is_empty(char *s);

int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

#endif