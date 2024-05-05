/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:41:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/06 00:43:09 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **stack_a, int ac)
{
	unsigned int	size_a;
	t_list			**stack_b;

	size_a = ft_lstsize(*stack_a);
	stack_b = malloc(sizeof(t_list) * (ac - 1));
	if (!stack_b)
		free_and_exit(stack_a, NULL);
	*stack_b = NULL;
	if (size_a == 2)
		sa(stack_a);
	else if (size_a == 3)
		sort_3(stack_a);
	else if (size_a > 3 && size_a <= 6)
		sort_3_to_6(size_a, stack_a, stack_b);
	else
		sort_big(size_a, stack_a, stack_b);
	free_nodes(stack_b);
	free(stack_b);
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
	free_nodes(stack_a);
	free(stack_a);
	free(nums);
	return (0);
}
