# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 23:14:11 by dmodrzej          #+#    #+#              #
#    Updated: 2024/03/10 12:57:04 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_strlen.c ft_strncmp.c \
			ft_bzero.c ft_memset.c ft_memcpy.c ft_tolower.c \
			ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_memmove.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_memchr.c ft_memcmp.c ft_strlcpy.c \
			ft_strlcat.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_striteri.c ft_strmapi.c
			
BONUS	=	ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
			ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstmap.c
					
FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

BONUS_O	=	$(BONUS:.c=.o)

%.o: %.c libft.h
	cc $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus:		$(NAME) $(BONUS_O)
			ar -rcs $(NAME) $(BONUS_O)

clean:
			rm -f $(OBJS) $(BONUS_O)

fclean:		clean
			rm -f $(NAME)

re:			fclean all bonus

.PHONY:		all bonus clean fclean re
