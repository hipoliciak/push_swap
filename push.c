/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:41:16 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/05 02:00:45 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (!*stack_2)
		return ;
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	ft_lstadd_front(stack_1, tmp);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
