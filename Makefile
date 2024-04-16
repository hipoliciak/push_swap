# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 22:01:08 by dmodrzej          #+#    #+#              #
#    Updated: 2024/04/17 00:28:54 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c ops.c utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) libft
			$(CC) $(FLAGS) $(OBJS) -o $@ -L libft -lft

libft:
			make -C libft

remlib:
			make clean -C libft

clean:		remlib
			rm -f $(OBJS)

fclean:		clean
			rm -f push_swap libft/libft.a

re:			fclean all

.PHONY:		all push_swap libft remlib clean fclean re
