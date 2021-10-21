/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequences_of_moves_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:47:50 by esafar            #+#    #+#             */
/*   Updated: 2021/10/21 16:46:32 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra_sa_ra_ra(long int *stack_a)
{
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
	rotate_a(stack_a, 1);
}

void	sa_rra_sa(long int *stack_a)
{
	swap_a(stack_a, 1);
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
}

void	rra_sa_ra_ra_sa(long int *stack_a)
{
	reverse_a(stack_a, 1);
	swap_a(stack_a, 1);
	rotate_a(stack_a, 1);
	rotate_a(stack_a, 1);
	swap_a(stack_a, 1);
}

void	sa_rra(long int *stack_a)
{
	swap_a(stack_a, 1);
	reverse_a(stack_a, 1);
}
