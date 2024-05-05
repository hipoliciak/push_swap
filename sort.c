/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:01:36 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/06 00:50:44 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack)->content;
	num2 = (*stack)->next->content;
	num3 = (*stack)->next->next->content;
	if (num1 == stack_min(stack) && num2 == stack_max(stack))
	{
		rra(stack);
		sa(stack);
	}
	else if (num1 == stack_max(stack) && num2 == stack_min(stack))
		ra(stack);
	else if (num1 == stack_max(stack) && num3 == stack_min(stack))
	{
		sa(stack);
		rra(stack);
	}
	else if (num2 == stack_min(stack) && num3 == stack_max(stack))
		sa(stack);
	else if (num2 == stack_max(stack) && num3 == stack_min(stack))
		rra(stack);
}

void	sort_3_to_6(unsigned int size_a, t_list **stack_a, t_list **stack_b)
{
	while (size_a > 3)
	{
		if ((*stack_a)->content == stack_min(stack_a))
		{
			pb(stack_a, stack_b);
			size_a--;
		}
		else if ((*stack_a)->next->content == stack_min(stack_a))
			sa(stack_a);
		else if (ft_lstlast(*stack_a)->content == stack_min(stack_a))
			rra(stack_a);
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void	sort_stack_a(t_list **stack_a, t_list **stack_b, int bit_pos)
{
	int	count;
	int	size_a;

	count = 0;
	size_a = ft_lstsize(*stack_a);
	while (*stack_a && count++ < size_a && !is_sorted(stack_a))
	{
		if (((*stack_a)->index & bit_pos) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

static void	sort_stack_b(t_list **stack_a, t_list **stack_b, int bit_pos)
{
	int	bit_pos_2;
	int	count;
	int	size_b;

	count = 0;
	bit_pos_2 = bit_pos;
	bit_pos_2 <<= 1;
	size_b = ft_lstsize(*stack_b);
	while (*stack_b && count++ < size_b && !is_rev_sorted(stack_b))
	{
		if (((*stack_b)->index & bit_pos_2) == 0)
			rb(stack_b);
		else
			pa(stack_a, stack_b);
	}
}

void	sort_big(unsigned int size_a, t_list **stack_a, t_list **stack_b)
{
	int				bit_pos;
	int				bit_max_pos;

	bit_pos = 1;
	bit_max_pos = 1;
	while (size_a > 0)
	{
		size_a /= 2;
		bit_max_pos *= 2;
	}
	while (!is_sorted(stack_a) && bit_pos < bit_max_pos)
	{
		sort_stack_a(stack_a, stack_b, bit_pos);
		sort_stack_b(stack_a, stack_b, bit_pos);
		bit_pos <<= 1;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
