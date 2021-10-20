/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3xxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:24:38 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 17:30:32 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_34xx(long int *stack_a)
{
	ra_ra(stack_a);
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a, 1);
}

void	case_31xx(long int *stack_a)
{
	if (stack_a[2] < stack_a[3])
		rra_sa_ra_ra(stack_a);
	else
		sa_rra_sa(stack_a);
}

void	case_32xx(long int *stack_a)
{
	if (stack_a[2] < stack_a[3])
		rra_sa_ra_ra_sa(stack_a);
	else
		sa_rra(stack_a);
}
