/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:31:03 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/20 20:32:15 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
