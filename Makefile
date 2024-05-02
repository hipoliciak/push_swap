# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 22:01:08 by dmodrzej          #+#    #+#              #
#    Updated: 2024/05/02 11:49:29 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c utils.c swap.c push.c rotate.c \
			reverse_rotate.c sort.c sort_utils.c \
			list_mgmt.c libft_functions.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f push_swap

re:			fclean all

.PHONY:		all clean fclean re
