/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:31:03 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/27 23:40:21 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (*(long *)tmp->content > *(long *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_min(t_list **stack)
{
	t_list	*stack_test;
	int		min;

	stack_test = *stack;
	min = *(int *)stack_test->content;
	while (stack_test)
	{
		if (*(int *)stack_test->content < min)
			min = *(int *)stack_test->content;
		stack_test = stack_test->next;
	}
	return (min);
}

int	stack_max(t_list **stack)
{
	t_list	*stack_test;
	int		max;

	stack_test = *stack;
	max = *(int *)stack_test->content;
	while (stack_test)
	{
		if (*(int *)stack_test->content > max)
			max = *(int *)stack_test->content;
		stack_test = stack_test->next;
	}
	return (max);
}

void	add_index(unsigned int size_a, t_list **stack_a)
{
	t_list			*stack_test;
	unsigned int	index;
	int				smallest;

	index = 0;
	smallest = stack_min(stack_a);
	while (index < size_a)
	{
		stack_test = *stack_a;
		while (stack_test)
		{
			if (*(int *)stack_test->content == smallest)
			{
				stack_test->index = index;
				index++;
				break ;
			}
			else
				stack_test = stack_test->next;
		}
		smallest++;
	}
}
