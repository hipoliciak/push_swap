/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:41:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/10 19:52:44 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nums(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] == ' ' || argv[i][j] == '\t'
				|| argv[i][j] == '\n' || argv[i][j] == '\v'
				|| argv[i][j] == '\f' || argv[i][j] == '\r')
				j++;
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] < '0' || argv[i][j] > '9')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	*new;

	stack_a = malloc(sizeof(t_stack) * (argc - 1));
	stack_b = malloc(sizeof(t_stack) * (argc - 1));
	if (argc <= 1)
	{
		free(stack_a);
		free(stack_b);
		exit (0);
	}
	if (check_nums(argc, argv) == 1)
		free_and_exit(stack_a, stack_b);
	if (check_duplicates(argc, argv) == 1)
		free_and_exit(stack_a, stack_b);
	while (argc > 1)
	{
		if (ft_atoi(argv[argc - 1]) > INT_MAX || ft_atoi(argv[argc - 1]) < INT_MIN)
			free_and_exit(stack_a, stack_b);
		new = ft_new_num(ft_atoi(argv[argc - 1]));
		printf("num pos stack_a %d = %d\n", argc - 2, new->num);
		ft_stack_add_back(stack_a, new);
		argc--;
	}
	printf("stack_a size = %d\n", ft_stack_size(*stack_a));
	printf("stack_b size = %d\n", ft_stack_size(*stack_b));
	free(stack_a);
	free(stack_b);
	ft_putstr_fd("OK\n", 1);
	return (0);
}