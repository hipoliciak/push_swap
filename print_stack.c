/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:23:29 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/06 00:01:57 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i > 0)
	{
		bit = (octet >> (i - 1) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

void	print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		print_bits(tmp->index);
		ft_putchar_fd('\t', 1);
		ft_putnbr_fd(tmp->index, 1);
		ft_putchar_fd('\t', 1);
		ft_putnbr_fd(tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}
