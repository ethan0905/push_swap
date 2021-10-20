/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences_of_moves_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:47:12 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 16:47:43 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_pb_sab_pa_pa(long int *stack_a, long int *stack_b, int ac)
{
	push_b(stack_a, stack_b, ac, 1);
	push_b(stack_a, stack_b, ac, 1);
	swap_ab(stack_a, stack_b, 1);
	push_a(stack_a, stack_b, ac, 1);
	push_a(stack_a, stack_b, ac, 1);
}

void	sa_ra_sa(long int *stack_a)
{
	swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
	swap_a(stack_a, 1);
}

void	ra_sa_ra_ra(long int *stack_a)
{
	rotate_a(stack_a, 1);
	swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
	rotate_a(stack_a, 1);
}

void	ra_ra_sa_ra(long int *stack_a)
{
	rotate_a(stack_a, 1);
	rotate_a(stack_a, 1);
	swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
}

void	ra_ra(long int *stack_a)
{
	rotate_a(stack_a, 1);
	rotate_a(stack_a, 1);
}
