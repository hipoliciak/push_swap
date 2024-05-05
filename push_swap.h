/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:58:42 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/06 00:52:31 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	unsigned int	index;
	int				has_index;
	struct s_list	*next;
}	t_list;

// Stack printing
void	print_stack(t_list **stack);
void	print_bits(unsigned char octet);
void	ft_putnbr_fd(int n, int fd);

// List mgmt
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(long content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

// Sort functions
void	sort_3(t_list **stack);
void	sort_3_to_6(unsigned int size_a, t_list **stack_a, t_list **stack_b);
void	sort_big(unsigned int size_a, t_list **stack_a, t_list **stack_b);

// Sort utils
int		is_sorted(t_list **stack);
int		is_rev_sorted(t_list **stack);
int		stack_min(t_list **stack);
int		stack_max(t_list **stack);
void	add_index(unsigned int size_a, t_list **stack_a);

// Other utils
int		check_duplicates(int ac, char **av);
int		is_nums(int ac, char **av);
void	fill_stack(t_list **stack_a, long *nums, int ac, char **av);
void	free_nodes(t_list **stack);
void	free_and_exit(t_list **stack_a, t_list **stack_b);

// Libft functions
long	ft_atoli(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

// Swap ops
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// Push ops
void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// Rotate ops
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// Reverse rotate ops
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
