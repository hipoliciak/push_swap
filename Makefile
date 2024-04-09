# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 22:01:08 by dmodrzej          #+#    #+#              #
#    Updated: 2024/04/09 22:06:56 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c ops.c utils.c
					
FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

%.o: %.c push_swap.h
	cc $(FLAGS) -c $< -o $@

all:		$(NAME)

${NAME}: ${OBJS}
	cc ${FLAGS} ${OBJS} -o ${NAME}

clean:
			rm -f $(OBJS) $(BONUS_O)

fclean:		clean
			rm -f $(NAME)

re:			fclean all bonus

.PHONY:		all bonus clean fclean re
