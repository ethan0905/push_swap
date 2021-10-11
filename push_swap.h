/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:17:47 by esafar            #+#    #+#             */
/*   Updated: 2021/10/08 14:00:44 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_data{

	int ac;
	int count_tmp;
	int remain_b;
	int min;
	int	max;
} t_data;

int	main(int ac, char **av);
void	swap_a(int *stackA, int print);
void	swap_b(int *stackB, int print);
void	swap_ab(int *stackA, int *stackB, int print);
void	push_b(int *stackA, int *stackB, int ac, int print);
void	push_a(int *stackA, int *stackB, int ac, int print);
void	rotate_a(int *stackA, int print);
void	rotate_b(int *stackB, int print);
void	rotate_ab(int *stackA, int *stackB, int print);
void	reverse_a(int *stackA, int print);
void	reverse_b(int *stackB, int print);
void	reverse_ab(int *stackA, int *stackB, int print);

void	print_table(int *stackA, int *stackB);
int		solve(int *stackA, int *stackB, int ac);
void	initialize(t_data *data, int ac);

#endif
