# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 22:01:08 by dmodrzej          #+#    #+#              #
#    Updated: 2024/04/20 21:26:16 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c swap.c push.c utils.c rotate.c \
			reverse_rotate.c sort.c sort_utils.c \

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

cleanlib:
			make clean -C libft

clean:		cleanlib
			rm -f $(OBJS)

fclean:		clean
			rm -f push_swap libft/libft.a

re:			fclean all

.PHONY:		all push_swap libft cleanlib clean fclean re
