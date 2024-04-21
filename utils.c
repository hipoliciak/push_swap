/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:29:37 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/21 14:40:51 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoli(av[i]) == ft_atoli(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_nums(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while (av[i][j] == ' ' || av[i][j] == '\t'
				|| av[i][j] == '\n' || av[i][j] == '\v'
				|| av[i][j] == '\f' || av[i][j] == '\r')
				j++;
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			while (av[i][j] != '\0')
			{
				if (av[i][j] < '0' || av[i][j] > '9')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	fill_stack(t_list **stack_a, long *nums, int ac, char **av)
{
	int		i;

	i = 0;
	while (i < (ac - 1))
	{
		nums[i] = ft_atoli(av[i + 1]);
		if (nums[i] > INT_MAX || nums[i] < INT_MIN)
			free_and_exit(stack_a, NULL);
		ft_lstadd_back(stack_a, ft_lstnew(&nums[i]));
		i++;
	}
}

void	free_and_exit(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(stack_a);
	free(stack_b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
