/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2xxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:23:47 by esafar            #+#    #+#             */
/*   Updated: 2021/10/27 11:35:02 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	case_21xx(long int *stack_a, long int *stack_b, int ac)
{
	if (stack_a[2] < stack_a[3])
		swap_a(stack_a, 1);
	else
		pb_pb_sab_pa_pa(stack_a, stack_b, ac);
}

void	case_24xx(long int *stack_a)
{
	if (stack_a[2] < stack_a[3])
		sa_ra_sa(stack_a);
	else
		ra_sa_ra_ra(stack_a);
}

void	case_23xx(long int *stack_a)
{
	if (stack_a[2] < stack_a[3])
		ra_ra_sa_ra(stack_a);
	else
		reverse_a(stack_a, 1);
}
