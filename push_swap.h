/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:58:42 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/09 22:55:27 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int			check_duplicates(int argc, char **argv);
int			check_nums(int argc, char **argv);
int			ft_strcmp(char *s1, char *s2);
long int	ft_atoi(const char *str);
void		free_and_exit(int *stack_a, int *stack_b);
void		ft_putstr_fd(char *str, int fd);
void		swap_a(int *a, int *b);
void		swap_b(int *a, int *b);

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;
#endif
