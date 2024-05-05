# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 22:01:08 by dmodrzej          #+#    #+#              #
#    Updated: 2024/05/05 22:43:27 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c utils.c swap.c push.c rotate.c \
			reverse_rotate.c sort.c sort_utils.c \
			list_mgmt.c libft_functions.c print_stack.c

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

# tests for checker_linux
test_dup: $(NAME) 
	$(eval ARG = $(100 0 -100 0))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind --leak-check=full ./push_swap $(ARG)

test2: $(NAME) 
	$(eval ARG = $(shell seq -1000 1000 | shuf -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind --leak-check=full ./push_swap $(ARG)

test3: $(NAME) 
	$(eval ARG = $(shell seq -1000 1000 | shuf -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind --leak-check=full ./push_swap $(ARG)

test5: $(NAME) 
	$(eval ARG = $(shell seq -1000 1000 | shuf -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind --leak-check=full ./push_swap $(ARG)

test100: $(NAME) 
	$(eval ARG = $(shell seq -1000 1000 | shuf -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind --leak-check=full ./push_swap $(ARG)

test500: $(NAME) 
	$(eval ARG = $(shell seq -1000 1000 | shuf -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of instructions: "
	@./push_swap $(ARG) | wc -l
	valgrind --leak-check=full ./push_swap $(ARG)

.PHONY:		all clean fclean re test2 test3 test5 test100 test500
