/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:41:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/21 14:45:33 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list **stack)
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

int	main(int ac, char **av)
{
	t_list	**stack_a;
	long	*nums;

	if (ac <= 1)
		exit (0);
	if (is_nums(ac, av))
		free_and_exit(NULL, NULL);
	stack_a = malloc(sizeof(t_list) * (ac - 1));
	if (!stack_a)
		exit (1);
	*stack_a = NULL;
	if (check_duplicates(ac, av))
		free_and_exit(stack_a, NULL);
	nums = malloc(sizeof(long) * (ac - 1));
	if (!nums)
		free_and_exit(stack_a, NULL);
	fill_stack(stack_a, nums, ac, av);
	if (!is_sorted(stack_a))
		sort(stack_a, ac);
	free_stack(stack_a);
	free(stack_a);
	free(nums);
	return (0);
}

	// ft_putendl_fd("Stack is sorted, no moves needed", 1);
	// while (*stack_a)
	// {
	// 	ft_putnbr_fd(*(int *)(*stack_a)->content, 1);
	// 	ft_putchar_fd(' ', 1);
	// 	*stack_a = (*stack_a)->next;
	// }
	// ft_putchar_fd('\n', 1);