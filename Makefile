# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esafar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 16:19:49 by esafar            #+#    #+#              #
#    Updated: 2021/10/12 16:45:10 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	   ./srcs/operations1.c \
	   solve.c

LIBFT = ./libft/ft_putchar_fd.c \
		./libft/ft_atoi.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strlen.c \
		./libft/ft_itoa.c \
		./libft/ft_strlcpy.c

OBJS = ${SRCS:.c=.o} ${LIBFT:.c=.o}

#CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
#	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${NAME} ${OBJS}

re: fclean all
