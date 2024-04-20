/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:41:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/20 13:25:00 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*ft_lstnew(int num)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return (0);
// 	new->num = num;
// 	new->next = 0;
// 	return (new);
// }

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

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*stack_test;

	if (ac <= 1)
		exit (0);
	stack_a = malloc(sizeof(t_list *) * (ac - 1));
	stack_b = malloc(sizeof(t_list *) * (ac - 1));
	if (check_nums(ac, av) == 1)
		free_and_exit(stack_a, NULL);
	if (check_duplicates(ac, av) == 1)
		free_and_exit(stack_a, NULL);
	fill_stack(stack_a, ac, av);
	stack_test = *stack_a;
	printf("stack_a pos%d = %ld\n", 0, *(long *)stack_test->content);
	sa(stack_a);
	stack_test = *stack_a;
	printf("stack_a pos%d = %ld\n", 0, *(long *)stack_test->content);
	pb(stack_a, stack_b);
	stack_test = *stack_b;
	printf("stack_b pos%d = %ld\n", 0, *(long *)stack_test->content);
	stack_test = *stack_a;
	printf("stack_a pos%d = %ld\n", 0, *(long *)stack_test->content);
	ra(stack_a);
	stack_test = ft_lstlast(*stack_a);
	printf("stack_a pos last = %ld\n", *(long *)stack_test->content);
	stack_test = *stack_a;
	printf("stack_a pos%d = %ld\n", 0, *(long *)stack_test->content);
	printf("stack_a size = %d\n", ft_lstsize(*stack_a));
	printf("stack_b size = %d\n", ft_lstsize(*stack_b));
	return (0);
}
