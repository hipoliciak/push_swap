/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:41:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/27 23:40:29 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
