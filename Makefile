# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esafar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 16:19:49 by esafar            #+#    #+#              #
#    Updated: 2021/10/20 19:20:54 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	   solve.c \
	   ./srcs/swap.c \
	   ./srcs/push.c \
	   ./srcs/rotate.c \
	   ./srcs/reverse.c \
	   ./sequences/sequences_of_moves_1.c \
	   ./sequences/sequences_of_moves_2.c \
	   ./sequences/sequences_of_moves_3.c \
	   ./sequences/sequences_of_moves_4.c \
	   ./cases/case_1xxx.c \
	   ./cases/case_2xxx.c \
	   ./cases/case_3xxx.c \
	   ./cases/case_4xxx.c \
	   ./solve/make_2.c \
	   ./solve/make_3.c \
	   ./solve/make_4.c \
	   ./solve/make_5.c \
	   ./check_and_error/check_and_error.c

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
