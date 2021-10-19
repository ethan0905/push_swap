/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:17:47 by esafar            #+#    #+#             */
/*   Updated: 2021/10/18 16:40:45 by esafar           ###   ########.fr       */
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
	int medA;
	int medB;
	int	max;
	int min_du_stack;
	int max_du_stack;
	int	ra_tmp;
	int	rb_tmp;
	int	rra_tmp;
	int	rrb_tmp;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
} t_data;

int	main(int ac, char **av);
void	swap_a(long int *stackA, int print);
void	swap_b(long int *stackB, int print);
void	swap_ab(long int *stackA, long int *stackB, int print);
void	push_b(long int *stackA, long int *stackB, int ac, int print);
void	push_a(long int *stackA, long int *stackB, int ac, int print);
void	rotate_a(long int *stackA, int print);
void	rotate_b(long int *stackB, int print);
void	rotate_ab(long int *stackA, long int *stackB, int print);
void	reverse_a(long int *stackA, int print);
void	reverse_b(long int *stackB, int print);
void	reverse_ab(long int *stackA, long int *stackB, int print);

void	b_pas_zero(long int *tab);
void	print_table(long int *stackA, long int *stackB);
int		solve(long int *stackA, long int *stackB, int ac);
void	initialize(t_data *data, int ac);

#endif
