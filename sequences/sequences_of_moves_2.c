/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences_of_moves_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:46:20 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 16:47:06 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_rra_sa_rra_rra(long int *stack_a)
{
	reverse_a(stack_a, 1);
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
	reverse_a(stack_a, 1);
	reverse_a(stack_a, 1);
}

void	ra_sa_rra(long int *stack_a)
{
	rotate_a(stack_a, 1);
	swap_a(stack_a, 1);
	reverse_a(stack_a, 1);
}

void	rra_sa(long int *stack_a)
{
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
}

void	rra_sa_rra_sa(long int *stack_a)
{
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
}

void	pb_sa_rra_pa(long int *stack_a, long int *stack_b, int ac)
{
	push_b(stack_a, stack_b, ac, 1);
	swap_a(stack_a, 1);
	reverse_a(stack_a, 1);
	push_a(stack_a, stack_b, ac, 1);
}
