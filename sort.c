/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:01:36 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/28 02:38:40 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, int ac)
{
	unsigned int	size_a;
	t_list			**stack_b;

	size_a = ft_lstsize(*stack_a);
	stack_b = malloc(sizeof(t_list) * (ac - 1));
	if (!stack_b)
		free_and_exit(stack_a, NULL);
	*stack_b = NULL;
	add_index(size_a, stack_a);
	if (size_a == 2)
		sa(stack_a);
	else if (size_a == 3)
		sort_3(stack_a);
	else if (size_a > 3 && size_a <= 6)
		sort_3_to_6(size_a, stack_a, stack_b);
	else
		sort_big(size_a, stack_a, stack_b);
	free_stack(stack_b);
	free(stack_b);
}

void	sort_3(t_list **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = *(int *)(*stack)->content;
	num2 = *(int *)(*stack)->next->content;
	num3 = *(int *)(*stack)->next->next->content;
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
		if (*(int *)(*stack_a)->content == stack_min(stack_a))
		{
			pb(stack_a, stack_b);
			size_a--;
		}
		else if (*(int *)(*stack_a)->next->content == stack_min(stack_a))
			sa(stack_a);
		else if (*(int *)ft_lstlast(*stack_a)->content == stack_min(stack_a))
			rra(stack_a);
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_big(unsigned int size_a, t_list **stack_a, t_list **stack_b)
{
	int				bit_pos;
	unsigned int	count;

	bit_pos = 1;
	while (!is_sorted(stack_a))
	{
		count = 0;
		while (*stack_a != NULL && count++ < size_a)
		{
			if (((*stack_a)->index & bit_pos) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		bit_pos *= 2;
	}
}
