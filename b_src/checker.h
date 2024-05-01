/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:11:00 by anamella          #+#    #+#             */
/*   Updated: 2024/05/01 23:27:17 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_node(int data);

void	l_add_node(t_stack **head, t_stack *node_to_add);
void	f_add_node(t_stack **head, t_stack *node_to_add);
void	free_node(t_stack *stack_free);

char	**new_str(char **av);
char	**ft_split(char const *s, char c);
char	**ft_free(char **ptr);

int		moves_check(char *s, t_stack **stack_a, t_stack **stack_b);
int		get_moves(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack_a, t_stack *stack_b);
int		ft_strcmp(char *s, char *s1);
int		link_len(t_stack *stack_t);
int		ft_atoi(const char *str);
int		check_error(char **str);
int		is_number(char *s);
int		is_dup(char **str);
int		is_int(char *s);

int		rrr(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);

#endif