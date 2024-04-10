/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:58:42 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/10 20:02:59 by dmodrzej         ###   ########.fr       */
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
void		ft_putstr_fd(char *str, int fd);

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

void		free_and_exit(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_new_num(int num);
int			ft_stack_size(t_stack *stack);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack		*ft_stack_last(t_stack *stack);

void		swap(t_stack *stack);

#endif
