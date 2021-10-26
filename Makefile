# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esafar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 16:19:49 by esafar            #+#    #+#              #
#    Updated: 2021/10/26 13:52:13 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	   solve.c \
	   ./solve/operations/swap.c \
	   ./solve/operations/push.c \
	   ./solve/operations/rotate.c \
	   ./solve/operations/reverse.c \
	   ./solve/sequences/sequences_of_moves_1.c \
	   ./solve/sequences/sequences_of_moves_2.c \
	   ./solve/sequences/sequences_of_moves_3.c \
	   ./solve/sequences/sequences_of_moves_4.c \
	   ./solve/sequences/cases/case_1xxx.c \
	   ./solve/sequences/cases/case_2xxx.c \
	   ./solve/sequences/cases/case_3xxx.c \
	   ./solve/sequences/cases/case_4xxx.c \
	   ./solve/make_2.c \
	   ./solve/make_3.c \
	   ./solve/make_4.c \
	   ./solve/make_5.c \
	   ./solve/utils.c \
	   ./solve/initialize.c \
	   ./solve/make_all/make_all.c \
	   ./solve/make_all/push_best_nb.c \
	   ./solve/make_all/initialize_count_for_rr_rrr.c \
	   ./solve/make_all/check_count.c \
	   ./solve/make_all/get_ca.c \
	   ./solve/make_all/insert_sort.c \
	   ./solve/make_all/ra_or_rra.c \
	   ./solve/make_all/rfx_or_rrfx.c \
	   ./solve/make_all/pb_rb.c \
	   ./solve/make_all/free_alias.c \
	   ./solve/check_and_error/check_and_error.c

LIBFT = ./libft/ft_putchar_fd.c \
		./libft/ft_atoi.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strlen.c \
		./libft/ft_itoa.c \
		./libft/ft_strlcpy.c

OBJS = ${SRCS:.c=.o} ${LIBFT:.c=.o}

#CFLAGS = -Wall -Wextra -Werror

all:	${NAME}
	rm -f ${OBJS}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
#	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${NAME} ${OBJS}

re: fclean all
