/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:29:37 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/20 13:09:49 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **stack_a, int argc, char **argv)
{
	int		i;
	long	*num;

	num = malloc(sizeof(long) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		num[i] = ft_atoli(argv[i]);
		if (num[i] > INT_MAX || num[i] < INT_MIN)
			free_and_exit(stack_a, NULL);
		ft_lstadd_back(stack_a, ft_lstnew(&num[i]));
		i++;
	}
}

void	free_and_exit(t_list **stack_a, t_list **stack_b)
{
	free(stack_a);
	free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

long	ft_atoli(const char *str)
{
	int		i;
	long 	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}
