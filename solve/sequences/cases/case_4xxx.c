/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_4xxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:26:05 by esafar            #+#    #+#             */
/*   Updated: 2021/10/20 17:30:42 by esafar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_4xxx(long int *stack_a)
{
	if (stack_a[2] > stack_a[3] && stack_a[1] < stack_a[3])
		rra_rra_sa_rra(stack_a);
	else if (stack_a[2] > stack_a[3] && stack_a[1] > stack_a[3] && stack_a[1] < stack_a[2])
		rra_sa_ra(stack_a);
	else if (stack_a[1] < stack_a[2] && stack_a[2] < stack_a[3])
		rotate_a(stack_a, 1);
	else if (stack_a[1] > stack_a[2] && stack_a[1] > stack_a[3])
	{
		if (stack_a[2] < stack_a[3])
			sa_ra_ra(stack_a);
		else
			sa_rra_rra_sa(stack_a);
	}
	else if (stack_a[2] < stack_a[1] && stack_a[1] < stack_a[3])
		ra_sa(stack_a);
}
