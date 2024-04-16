/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:58:42 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/04/17 00:23:33 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

int			check_duplicates(int argc, char **argv);
int			check_nums(int argc, char **argv);
int			ft_strcmp(char *s1, char *s2);
long int	ft_atoli(const char *str);
void		swap(t_list *stack);
void		free_and_exit(t_list **stack_a, t_list **stack_b);

#endif
