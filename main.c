/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:41:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/20 21:56:22 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;

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
	fill_stack(stack_a, ac, av);
	if (!is_sorted(stack_a))
	{
		ft_putstr_fd("Stack is sorted, no moves needed\n", 1);
		free(stack_a);
		exit (0);
	}
	sort(stack_a, ac);
	while (*stack_a)
	{
		ft_putnbr_fd(*(int *)(*stack_a)->content, 1);
		ft_putchar_fd(' ', 1);
		stack_a = &(*stack_a)->next;
	}
	ft_putchar_fd('\n', 1);
	ft_lstclear(stack_a, free);
	return (0);
}
