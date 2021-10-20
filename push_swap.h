/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:17:47 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 19:21:54 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_data{
	int	ac;
	int	count_tmp;
	int	remain_b;
	int	min;
	int	med_a;
	int	med_b;
	int	max;
	int	min_du_stack;
	int	max_du_stack;
	int	ra_tmp;
	int	rb_tmp;
	int	rra_tmp;
	int	rrb_tmp;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	count_ra;
	int	count_rb;
	int	count_rra;
	int	count_rrb;
}	t_data;

//OPERATIONS
void	swap_a(long int *stack_a, int print);
void	swap_b(long int *stack_b, int print);
void	swap_ab(long int *stack_a, long int *stack_b, int print);
void	push_b(long int *stack_a, long int *stack_b, int ac, int print);
void	push_a(long int *stack_a, long int *stack_b, int ac, int print);
void	rotate_a(long int *stack_a, int print);
void	rotate_b(long int *stack_b, int print);
void	rotate_ab(long int *stack_a, long int *stack_b, int print);
void	reverse_a(long int *stack_a, int print);
void	reverse_b(long int *stack_b, int print);
void	reverse_ab(long int *stack_a, long int *stack_b, int print);

//SEQUENCES
void	rra_rra_sa_rra(long int *stack_a);
void	rra_sa_ra(long int *stack_a);
void	sa_ra_ra(long int *stack_a);
void	sa_rra_rra_sa(long int *stack_a);
void	ra_sa(long int *stack_a);

void	rra_rra_sa_rra_rra(long int *stack_a);
void	ra_sa_rra(long int *stack_a);
void	rra_sa(long int *stack_a);
void	rra_sa_rra_sa(long int *stack_a);
void	pb_sa_rra_pa(long int *stack_a, long int *stack_b, int ac);

void	pb_pb_sab_pa_pa(long int *stack_a, long int *stack_b, int ac);
void	sa_ra_sa(long int *stack_a);
void	ra_sa_ra_ra(long int *stack_a);
void	ra_ra_sa_ra(long int *stack_a);
void	ra_ra(long int *stack_a);

void	rra_sa_ra_ra(long int *stack_a);
void	sa_rra_sa(long int *stack_a);
void	rra_sa_ra_ra_sa(long int *stack_a);
void	sa_rra(long int *stack_a);

//CASES X X X X
void	case_1xxx(long int *stack_a, long int *stack_b, int ac);

void	case_21xx(long int *stack_a, long int *stack_b, int ac);
void	case_23xx(long int *stack_a, long int *stack_b, int ac);
void	case_24xx(long int *stack_a, long int *stack_b, int ac);

void	case_31xx(long int *stack_a);
void	case_32xx(long int *stack_a);
void	case_34xx(long int *stack_a);

void	case_4xxx(long int *stack_a);

//CHECK DES ERREURS
int		ft_error(void);
int		check_tab(long int *stack_a, int size);
int		already_sorted(long int *stack_a, int size);

//INITIALISATION
int		main(int ac, char **av);
void	initialize(t_data *data, int ac);
void	b_pas_zero(long int *tab);
void	find_min_and_max_in_stack(long int *stack_a,
			long int *stack_b, t_data *data);

//AFFICHAGE
void	print_table(long int *stack_a, long int *stack_b);

//RESOLUTION
int		solve(long int *stack_a, long int *stack_b, int ac);

void	make_two(long int *stack_a);
void	make_three(long int *stack_a);
void	make_four(long int *stack_a, long int *stack_b, int ac);

void	high_five(long int *stack_a, long int *stack_b, int ac);
int		rotate_ou_reverse(long int *stack_a, int count_tmp, int i);
void	solve_my_five(long int *stack_a, long int *stack_b, t_data *data, int ac);

void	copy_stack(long int *dest, long int *src, int ac);
long int *sort_stack(long int *fant, t_data *data);

#endif
