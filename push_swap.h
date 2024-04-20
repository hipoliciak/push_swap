/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:58:42 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/20 13:17:33 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

int		check_duplicates(int argc, char **argv);
int		check_nums(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
long 	ft_atoli(const char *str);
void	free_and_exit(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack_a, int argc, char **argv);

// Swap ops
void	swap(t_list *stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// Push ops
void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// Rotate ops
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

#endif
