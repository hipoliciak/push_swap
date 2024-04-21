/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:58:42 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/21 14:43:24 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

// Sort
void	sort(t_list **stack_a, int ac);
void	sort_3(t_list **stack);
void	sort_3_to_5(unsigned int size_a, t_list **stack_a, t_list **stack_b);

// Sort utils
int		stack_min(t_list **stack);
int		stack_max(t_list **stack);

// Utils
int		check_duplicates(int ac, char **av);
int		is_nums(int ac, char **av);
void	free_and_exit(t_list **stack_a, t_list **stack_b);
void	fill_stack(t_list **stack_a, long *nums, int ac, char **av);
void	free_stack(t_list **stack);

// Swap ops
void	swap(t_list **stack);
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

// Reverse rotate ops
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
