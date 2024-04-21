/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:01:36 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/21 11:54:21 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_to_5(unsigned int size_a, t_list **stack_a, t_list **stack_b)
{
	while (size_a > 3)
	{
		if (*(int *)(*stack_a)->content == stack_min(stack_a))
		{
			pb(stack_a, stack_b);
			size_a--;
		}
		else if (*(int *)ft_lstlast(*stack_a)->content == stack_min(stack_a))
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			size_a--;
		}
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
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

void	sort(t_list **stack_a, int ac)
{
	unsigned int	size_a;
	t_list			**stack_b;

	stack_b = malloc(sizeof(t_list) * (ac - 1));
	if (!stack_b)
		free_and_exit(stack_a, NULL);
	*stack_b = NULL;
	size_a = ft_lstsize(*stack_a);
	if (size_a == 2)
		sa(stack_a);
	else if (size_a == 3)
		sort_3(stack_a);
	else if (size_a > 3 && size_a <= 5)
		sort_3_to_5(size_a, stack_a, stack_b);
	else
		ft_putendl_fd("Sort not implemented yet", 1);
	ft_lstclear(stack_b, free);
	free(stack_b);
}
