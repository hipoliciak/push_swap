/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:31:03 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/05 22:19:19 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index < tmp->next->index
			&& (tmp->next->index - tmp->index) == 1)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	is_rev_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index
			&& (tmp->index - tmp->next->index) == 1)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	stack_min(t_list **stack)
{
	t_list	*stack_test;
	int		min;

	stack_test = *stack;
	min = stack_test->content;
	while (stack_test)
	{
		if (stack_test->content < min)
			min = stack_test->content;
		stack_test = stack_test->next;
	}
	return (min);
}

int	stack_max(t_list **stack)
{
	t_list	*stack_test;
	int		max;

	stack_test = *stack;
	max = stack_test->content;
	while (stack_test)
	{
		if (stack_test->content > max)
			max = stack_test->content;
		stack_test = stack_test->next;
	}
	return (max);
}

void	add_index(unsigned int size_a, t_list **stack_a)
{
	t_list			*tmp;
	t_list			*smallest_node;
	unsigned int	index;
	int				smallest;

	index = 0;
	smallest = stack_min(stack_a);
	while (index < size_a)
	{
		tmp = *stack_a;
		smallest = INT_MAX;
		while (tmp)
		{
			if (tmp->content < smallest && tmp->has_index == 0)
			{
				smallest_node = tmp;
				smallest = tmp->content;
			}
			tmp = tmp->next;
		}
		smallest_node->index = index;
		smallest_node->has_index = 1;
		index++;
	}
}
